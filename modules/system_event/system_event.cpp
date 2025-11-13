//=====[Libraries]=============================================================
#include "mbed.h"
#include "arm_book_lib.h"
#include "system_event.h"

//=====[Implementations of public methods]=========================

systemEvent::systemEvent(const char* eventLabel){
    strcpy( label, eventLabel );
    lastState = OFF;
}

void systemEvent::stateUpdate(bool state)
{
    if ( state != this->lastStateRead() ){
        eventLogWrite( state, this->getLabel() );
    }
    this->lastStateUpdate(state);
}

bool systemEvent::lastStateRead()
{
    return lastState;
}

char* systemEvent::getLabel()
{
    return label;
}

//=====[Implementations of private methods]====================================
void systemEvent::lastStateUpdate(bool state)
{
    lastState = state;
}