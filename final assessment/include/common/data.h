#ifndef __DATA_H__
#define __DATA_H__
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

/********************************************************************
 * Function:        uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
 *
 * PreCondition:    None
 *
 * Input:           data - Number to be converted in string
 *					ptr - poiter where the string starts
 *					base - the base number
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This functions take a number and convert to a string
 *					in base 2 to 16, as choose by the program.
 *
 *
 * Note:            None
 *
 *******************************************************************/
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base);


/********************************************************************
 * Function:        int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base);
 *
 * PreCondition:    None
 *
 * Input:           ptr - poiter where the string starts.
 *					digits - string length
 *					base - the base number
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This functions take a string and convert to a number
 *					based on base between 2 and 16.
 *
 *
 * Note:            None
 *
 *******************************************************************/

int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base);

#endif