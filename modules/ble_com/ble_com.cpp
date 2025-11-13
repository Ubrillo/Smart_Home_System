//=====[Libraries]====================================
#include "mbed.h"
#include "ble_com.h"
#include "gate.h"
#include "event_log.h"

//=====[Declaration and initialization of public global objects]========
UnbufferedSerial uartBle(p9, p10, 9600);

//=====[Declarations (prototypes) of private functions]==============
static char bleComCharRead();

//=====[Implementations of public functions]==============
void bleComUpdate()
{
    char receivedChar = bleComCharRead();
    if( receivedChar != '\0' ){
        switch (receivedChar){
            case 'O': gateOpen(); break;
            case 'C': gateClose(); break;
            case 'b': eventLogReport(); break;
        }
    }
}

void bleComStringWrite( const char* str )
{
    uartBle.write( str, strlen(str) );
}


//=====[Implementations of private functions]==============
static char bleComCharRead()
{
    char receivedChar = '\0';
    if( uartBle.readable() ){
        uartBle.read(&receivedChar,1);
    }
    return receivedChar;
}