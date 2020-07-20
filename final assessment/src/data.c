#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    uint16_t    forCounter = 0;
    uint32_t    characterQuantity = 0;
    int32_t     dataAlteredToCountHowManyCharacterWillHave;
    uint8_t     negativeFlag = 0;

    if( ( base == 10 ) && ( data & 0x80000000 ) ){
        data *= -1;
        negativeFlag = 1;
    }

    // Discovering how many characters is necessary to represent that number.
    dataAlteredToCountHowManyCharacterWillHave = data;
    while( dataAlteredToCountHowManyCharacterWillHave != 0 ){
        dataAlteredToCountHowManyCharacterWillHave = (int32_t)(dataAlteredToCountHowManyCharacterWillHave / base);
        characterQuantity++;
    }

    if( negativeFlag == 0 ){
        characterQuantity++;
        *( ptr + characterQuantity - 1 ) = 0;
        //ptr = (char*)malloc( characterQuantity * sizeof(char) );
        for( forCounter = 0 ; forCounter < ( characterQuantity - 1 ) ; forCounter++ ){
            *( ptr+(characterQuantity - 2 ) - forCounter ) = ( ( (int32_t)(data % base) ) < 10 )? ( ( (int32_t)(data % base) ) + 48 ) : ( ( (int32_t)(data % base) ) + 55 );
            data = (int32_t)(data / base);
        }
    } else {
        characterQuantity += 2;
        *( ptr + characterQuantity - 1 ) = 0;
        *ptr = 45;
        //ptr = (char*)malloc( characterQuantity * sizeof(char) );
        for( forCounter = 0 ; forCounter < ( characterQuantity - 2 ) ; forCounter++ ){
            *( ptr+(characterQuantity - 2 ) - forCounter ) = ( ( (int32_t)(data % base) ) < 10 )? ( ( (int32_t)(data % base) ) + 48 ) : ( ( (int32_t)(data % base) ) + 55 );
            data = (int32_t)(data / base);
        }
    }
    return characterQuantity;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    uint8_t     negativeFlag;
    uint16_t    forCounter;
    uint32_t     numberConverted = 0;

    digits--;
    if( ( base == 10 ) && ( *ptr == 45 ) ){
        negativeFlag = 1;
    }

    //forCounter = (negativeFlag == 1)? 1:0
    ptr = (negativeFlag == 1)? ( ptr + 1 ): ptr;
    forCounter = 0;
    while( (*(ptr+forCounter)) != 0 ){
        numberConverted += ( ( (*(ptr + forCounter) > 57 ) ? (*(ptr + forCounter) - 55) : (*(ptr + forCounter) - 48) ) * ( (int32_t)round( pow( base, ( digits - forCounter - 1 ) ) ) ) );
        forCounter++;
    }
    return (int32_t)( (negativeFlag == 1)? ( numberConverted * (-1) ): numberConverted );
}
