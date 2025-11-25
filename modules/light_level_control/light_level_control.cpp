//=====[Libraries]=============================================================
#include "arm_book_lib.h"
#include "smart_home_system.h"
#include "light_level_control.h"

//=====[Declaration and initialization of public global objects]===
AnalogIn potentiometer(p20);

//=====[Implementations of public functions]===================================
void lightLevelControlInit() { }
void lightLevelControlUpdate() { }

float lightLevelControlRead()
{
    return potentiometer.read();
}

//=====[Implementations of private functions]=============================