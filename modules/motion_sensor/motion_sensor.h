//=====[#include guards - begin]===============================================
#ifndef _MOTION_SENSOR_H_
#define _MOTION_SENSOR_H_

//=====[Declarations (prototypes) of public functions]=========================
void motionSensorInit();
bool motionSensorRead();
void motionSensorActivate();
void motionSensorDeactivate();

//=====[#include guards - end]=================================================
#endif // _MOTION_SENSOR_H_