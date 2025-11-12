//=====[#include guards - begin]==========
#ifndef _INTRUDER_ALARM_H_
#define _INTRUDER_ALARM_H_

//=====[Libraries]================
void intruderAlarmInit();
void intruderAlarmUpdate();
void intruderAlarmDeactivate();

bool intruderDetectorStateRead();
bool intruderDetectedRead();
//=====[#include guards - end]========

#endif