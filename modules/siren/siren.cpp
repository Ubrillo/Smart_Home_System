// //=====[Libraries]=============================================================
// #include "mbed.h"
// #include "arm_book_lib.h"
// #include "siren.h"
// #include "smart_home_system.h"

// //=====[Declaration of private defines]========================================

// //=====[Declaration of private data types]=====================================

// //=====[Declaration and initialization of public global objects]===============

// //DigitalOut sirenPin(p18);
// PwmOut speaker(p26);
// static bool sirenPin = OFF;

// //=====[Declaration of external public global variables]=======================

// //=====[Declaration and initialization of public global variables]=============

// //=====[Declaration and initialization of private global variables]============

// static bool sirenState = OFF;
// static void on_alarm();
// static void off_alarm();

// //=====[Declarations (prototypes) of private functions]========================

// //=====[Implementations of public functions]===================================

// void sirenInit()
// {
//     sirenPin = OFF;
// }

// bool sirenStateRead()
// {
//     return sirenState;
// }

// void sirenStateWrite( bool state )
// {
//     sirenState = state;
// }

// void sirenUpdate( int strobeTime )
// {
//     static int accumulatedTimeAlarm = 0;
//     accumulatedTimeAlarm = accumulatedTimeAlarm + SYSTEM_TIME_INCREMENT_MS;
    
//     if(sirenState) {
//         if(accumulatedTimeAlarm >= strobeTime ) {
//             accumulatedTimeAlarm = 0;
//             sirenPin = !sirenPin;
            
//             if (sirenPin){
//                 on_alarm();
//             }else{
//                 off_alarm();
//             }
//         }
//     } else {
//         //sirenPin = ON; original
//         sirenPin = OFF;
//         off_alarm(); //appended
//     }
// }

// static void on_alarm()
// {
//     float frequency = 440.0;
//     speaker.period(1.0 / frequency); // set PWM period
//     speaker = 0.5;                      // 50% duty cycle
// }

// static void off_alarm()
// {
//     speaker.period(0.0);
//     speaker = 0.0;  
// }

// //=====[Implementations of private functions]==================================



//=====[Libraries]=============================================================
#include "mbed.h"
#include "arm_book_lib.h"
#include "siren.h"
#include "smart_home_system.h"

//=====[Declaration and initialization of public global objects]===============
PwmOut sirenPin(p26);

//=====[Declaration and initialization of private global variables]============
static bool sirenState = OFF;
static int currentStrobeTime = 0;

//=====[Implementations of public functions]===================================

void sirenInit()
{
    sirenPin.period(1.0f);
    sirenPin.write(1.0f);
}

bool sirenStateRead()
{
    return sirenState;
}

void sirenStateWrite( bool state )
{
    sirenState = state;
}

void sirenUpdate( int strobeTime )
{
    if( sirenState ) {
        if (currentStrobeTime != strobeTime) {
            sirenPin.period( (float) strobeTime * 2 / 1000 );
            sirenPin.write(0.5f);
            currentStrobeTime = strobeTime;
        }
    }
    else {
        sirenPin.write(1.0f);
        currentStrobeTime = 0;
    }
}