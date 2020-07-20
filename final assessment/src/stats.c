#include <stdint.h>
#include <stdio.h>
#include "stats.h"
#include "platform.h"

unsigned char roundDouble( double numberToRound );

void print_statistics( unsigned char* numberSeries ){
	PRINTF( "\n\n=============================  Statistics:  =============================\n\n" );
	PRINTF( "Max:\t %d\n", find_maximum( &numberSeries[ 0 ], NUMBER_OF_ELEMENTS ) );
	PRINTF( "Min:\t %d\n", find_minimum( &numberSeries[ 0 ], NUMBER_OF_ELEMENTS ) );
	PRINTF( "Mean:\t %d\n", find_mean( &numberSeries[ 0 ], NUMBER_OF_ELEMENTS ) );
	PRINTF( "Median:\t %d\n", find_median( &numberSeries[ 0 ], NUMBER_OF_ELEMENTS ) );
}

void print_array( unsigned char* numberSeries, uint16_t length ){
	#ifdef VERBOSE
		uint8_t forCounter;

		PRINTF( "\n\n=============================  Array:  =============================\n" );
		for( forCounter = 0 ; forCounter < length ; forCounter++ ){
			PRINTF( "%d\n", numberSeries[ forCounter ] );
		}
	#endif
}

unsigned char find_mean( unsigned char* numberSeries, uint16_t length ){
	uint16_t forCounter;
	uint16_t sum;

	// Initialization...
	sum = 0;
	
	// Computing the sum of all elements on array;
	for( forCounter = 0 ; forCounter <  length ; forCounter++ ){
		sum += numberSeries[ forCounter ];
	}

	// Dividing by the number of elements in array
	return roundDouble( (double)sum / (double)length );
}

unsigned char find_median( unsigned char* numberSeries, uint16_t length ){
	uint16_t 	middleIndex;

	// Reorganizing the array in a decrease order...
	sort_array( numberSeries, NUMBER_OF_ELEMENTS );

	// If the number of elements on array is even...
	middleIndex = ( IS_EVEN( length )? ( (uint16_t)( length / 2 ) - 1 ) : ( (uint16_t)( length / 2 ) ) );
	return find_mean( &numberSeries[ middleIndex ], ( IS_EVEN( length )? 2 : 1 ) );
}


unsigned char find_maximum( unsigned char* numberSeries, uint16_t length ){
	unsigned char 		maxNumber;
	uint16_t	forCounter;

	// Initialization...
	maxNumber = numberSeries[ 0 ];
	

	for( forCounter = 0 ; forCounter < ( length - 1 ) ; forCounter++ ){
		maxNumber = MAX_BETWEEN_TWO_NUMBERS( maxNumber, numberSeries[ forCounter + 1 ] );
	}

	// Or as the array is decreasing organized the max number is the first element of the array...
	return maxNumber;
}

unsigned char find_minimum( unsigned char* numberSeries, uint16_t length ){
	unsigned char 		minNumber;
	uint16_t	forCounter;

	// Initialization...
	minNumber = numberSeries[ 0 ];
	
	for( forCounter = 0 ; forCounter < ( length - 1 ) ; forCounter++ ){
		minNumber = MIN_BETWEEN_TWO_NUMBERS( minNumber, numberSeries[ forCounter + 1 ] );
	}

	// Or as the array is decreasing organized the min number is the last element of the array...
	return minNumber;
}

void sort_array( unsigned char* numberSeries, uint16_t length ){
	uint8_t 	someNumberIsOutOfOrder;
	unsigned char		reorderAux; 
	uint8_t 	forCounter;

	// Initialization...
	someNumberIsOutOfOrder = FALSE;

	for( forCounter = 0 ; forCounter < ( length - 1 ) ; forCounter++ ){
		if( numberSeries[ forCounter ] < numberSeries[ forCounter + 1 ] ){
			reorderAux = numberSeries[ forCounter ];
			numberSeries[ forCounter ] = numberSeries[ forCounter + 1 ];
			numberSeries[ forCounter + 1 ] = reorderAux;
			someNumberIsOutOfOrder = TRUE;
		}
	}

	if( someNumberIsOutOfOrder == TRUE ){
		sort_array( numberSeries, length );
	}
	
	return;
}

unsigned char roundDouble( double numberToRound ){
	if( ( ( (unsigned int)(numberToRound) + 1 ) - numberToRound ) > ( numberToRound - (unsigned int)(numberToRound) )  ){
		numberToRound = (unsigned char)numberToRound;
	} else {
		numberToRound = (unsigned char)(numberToRound) + 1 ;
	}
	return numberToRound;
}