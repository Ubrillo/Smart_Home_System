//=====[Libraries]=============================================================

#include "mbed.h"

#include "temperature_sensor.h"

#include "smart_home_system.h"

//=====[Declaration of private defines]========================================

#define LM35_NUMBER_OF_AVG_SAMPLES    10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//AnalogIn lm35(); - origianl
DigitalIn lm35(p13); //appended

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

float lm35TemperatureC = 0.0;
float lm35ReadingsArray[LM35_NUMBER_OF_AVG_SAMPLES];

//=====[Declarations (prototypes) of private functions]========================

static float analogReadingScaledWithTheLM35Formula( float analogReading );
static float getTemperatureReading();

//=====[Implementations of public functions]===================================

void temperatureSensorInit()
{
    int i;
    
    for( i=0; i<LM35_NUMBER_OF_AVG_SAMPLES ; i++ ) {
        lm35ReadingsArray[i] = 0;
    }
}

void temperatureSensorUpdate()
{
    static int lm35SampleIndex = 0;
    float lm35ReadingsSum = 0.0;
    float lm35ReadingsAverage = 0.0;

    int i = 0;

    //lm35ReadingsArray[lm35SampleIndex] = lm35.read();
    lm35ReadingsArray[lm35SampleIndex] = getTemperatureReading();
       lm35SampleIndex++;
    if ( lm35SampleIndex >= LM35_NUMBER_OF_AVG_SAMPLES) {
        lm35SampleIndex = 0;
    }
    
   lm35ReadingsSum = 0.0;
    for (i = 0; i < LM35_NUMBER_OF_AVG_SAMPLES; i++) {
        lm35ReadingsSum = lm35ReadingsSum + lm35ReadingsArray[i];
    }
    lm35ReadingsAverage = lm35ReadingsSum / LM35_NUMBER_OF_AVG_SAMPLES;
       //lm35TemperatureC = analogReadingScaledWithTheLM35Formula ( lm35ReadingsAverage );    
       lm35TemperatureC = lm35ReadingsAverage;

}


static float getTemperatureReading()
{
    I2C i2c(p28, p27);  // SDA, SCL lines on LPC1768 App Board
    const int LM75_ADDR = 0x48 << 1; // LM75BD 7-bit address shifted left for Mbed (8-bit format)
    
    char reg[1];
    char data[2];
    float temperature;

    reg[0] = 0x00;                      // Temperature register address
    i2c.write(LM75_ADDR, reg, 1);       // Point to temperature register
    i2c.read(LM75_ADDR, data, 2);       // Read two bytes

    int16_t raw = (data[0] << 8) | data[1];
    raw >>= 7;                          // Right shift to align bits
    temperature = raw * 0.5f;           // Each bit = 0.5°C

    return temperature;
}

float temperatureSensorReadCelsius()
{
    return lm35TemperatureC;
}

float temperatureSensorReadFahrenheit()
{
    return celsiusToFahrenheit( lm35TemperatureC );
}

float celsiusToFahrenheit( float tempInCelsiusDegrees )
{
    return ( tempInCelsiusDegrees * 9.0 / 5.0 + 32.0 );
}

//=====[Implementations of private functions]==================================

static float analogReadingScaledWithTheLM35Formula( float analogReading )
{
    return ( analogReading * 3.3 / 0.01 );
}