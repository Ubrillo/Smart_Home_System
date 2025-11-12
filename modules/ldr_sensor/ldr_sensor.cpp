//=====[Libraries]=============================================================
#include "arm_book_lib.h"
#include "smart_home_system.h"
#include "ldr_sensor.h"


//=====[Declaration and initialization of public global objects]==========
AnalogIn LDR(p18);

//=====[Implementations of public functions]===============
void ldrSensorInit() { }
void ldrSensorUpdate() { }

float ldrSensorRead()
{
    return LDR.read();
}

