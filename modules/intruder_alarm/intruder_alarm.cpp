//=====[Libraries]=============================================================
#include "mbed.h"
#include "arm_book_lib.h"
#include "intruder_alarm.h"
#include "motion_sensor.h"

//=====[Declaration and initialization of private global variables]====
static bool intruderDetected = OFF;
static bool intruderDetectorState = OFF;

//=====[Implementations of public functions]=======
void intruderAlarmInit()
{
    motionSensorInit();
}

void intruderAlarmUpdate()
{
    intruderDetectorState = motionSensorRead();
    if ( intruderDetectorState ) {
        intruderDetected = ON;
    }
}

bool intruderDetectorStateRead()
{
    return intruderDetectorState;
}

bool intruderDetectedRead()
{
    return intruderDetected;
}

void intruderAlarmDeactivate()
{
    intruderDetected = OFF;
}

