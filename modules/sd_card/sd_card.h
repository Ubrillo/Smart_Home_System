//=====[#include guards - begin]===============================================
#ifndef _SD_CARD_H_
#define _SD_CARD_H_

//=====[Declarations private defines]========
#define SD_CARD_MAX_FILE_LIST 10

//=====[Libraries]=============================================================
#define SD_CARD_FILENAME_MAX_LENGTH 32

//=====[Declarations (prototypes) of public functions]=========================
bool sdCardInit();
bool sdCardWriteFile( const char* fileName, const char* writeBuffer );
bool sdCardListFiles( char* fileNamesBuffer, int fileNamesBufferSize );
bool sdCardReadFile( const char* fileName, char * readBuffer, int readBufferSize );
//=====[#include guards - end]===============================
#endif // _SD_CARD_H_