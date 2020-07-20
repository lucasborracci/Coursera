#include <stdint.h>
#include <stdio.h>

#define NUMBER_OF_ELEMENTS					40
#define MAX_BETWEEN_TWO_NUMBERS( a, b )		( ( a > b ) ? a : b )
#define MIN_BETWEEN_TWO_NUMBERS( a, b )		( ( a < b ) ? a : b )
#define IS_EVEN( a )						( ( a % 2 ) == 0 )
#define TRUE								1
#define FALSE								0


/********************************************************************
 * Function:        void print_statistics( unsigned char* numberSeries );
 *
 * PreCondition:    None
 *
 * Input:           numberSeries - The sequence of numbers.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This functions gets a serie of numbers and calculates
 *					mean, median, minimum number and maximum number.
 *
 *
 * Note:            None
 *
 *******************************************************************/

void print_statistics( unsigned char* numberSeries );

/********************************************************************
 * Function:        void print_array( unsigned char* numberSeries, uint16_t length );
 *
 * PreCondition:    None
 *
 * Input:           numberSeries - The sequence of numbers.
 *					length - size of serie of numbers.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function prints the serie of numbers.
 *
 *
 * Note:            None
 *
 *******************************************************************/

void print_array( unsigned char* numberSeries, uint16_t length );


/********************************************************************
 * Function:        unsigned char find_mean( unsigned char* numberSeries, uint16_t length );
 *
 * PreCondition:    None
 *
 * Input:           numberSeries - The sequence of numbers.
 *					length - size of serie of numbers.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function takes a serie of numbers and calculates its mean.
 *
 *
 * Note:            None
 *
 *******************************************************************/

unsigned char find_mean( unsigned char* numberSeries, uint16_t length );


/********************************************************************
 * Function:        unsigned char find_median( unsigned char* numberSeries, uint16_t length );
 *
 * PreCondition:    None
 *
 * Input:           numberSeries - The sequence of numbers.
 *					length - size of serie of numbers.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function takes a serie of numbers and calculates its median.
 *
 *
 * Note:            None
 *
 *******************************************************************/

unsigned char find_median( unsigned char* numberSeries, uint16_t length );


/********************************************************************
 * Function:        unsigned char find_maximum( unsigned char* numberSeries, uint16_t length );
 *
 * PreCondition:    None
 *
 * Input:           numberSeries - The sequence of numbers.
 *					length - size of serie of numbers.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function takes a serie of numbers and find the maximum element value.
 *
 *
 * Note:            None
 *
 *******************************************************************/

unsigned char find_maximum( unsigned char* numberSeries, uint16_t length );


/********************************************************************
 * Function:        unsigned char find_minimum( unsigned char* numberSeries, uint16_t length );
 *
 * PreCondition:    None
 *
 * Input:           numberSeries - The sequence of numbers.
 *					length - size of serie of numbers.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function takes a serie of numbers and find the minimum element value.
 *
 *
 * Note:            None
 *
 *******************************************************************/

unsigned char find_minimum( unsigned char* numberSeries, uint16_t length );


/********************************************************************
 * Function:        void sort_array( unsigned char* numberSeries, uint16_t length );
 *
 * PreCondition:    None
 *
 * Input:           numberSeries - The sequence of numbers.
 *					length - size of serie of numbers.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function reorder the array in a decrease order.
 *
 *
 * Note:            None
 *
 *******************************************************************/

void sort_array( unsigned char* numberSeries, uint16_t length );
