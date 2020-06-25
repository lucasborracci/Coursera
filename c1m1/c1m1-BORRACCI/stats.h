/******************************************************************************
 * Copyright (C) 2020 Lucas Borracci
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief prints the array given.
 * 
 * This function takes an unsigned char array and its SIZE as parameters
 * It will print the array given in a column with the index of every element
 * 
 * @param Test,size
 * @return void
 */ 
  void print_array(unsigned char Test[], int size);
  
  
/**
 * @brief returns Median of an array.
 * 
 * This function returns the Median with an array of unsigned char type
 * and the SIZE as parameters.It returns a float.
 * 
 * @param Test
 * @param size
 * @return float
 */
  float find_median(unsigned char Test[], int size);
 
/**
 * @brief returns Mean of an array
 * 
 * This function returns the Mean with an array of unsigned char type
 * and the SIZE as parameters.It returns a float.
 * @param test
 * @param size
 * @return float
 */
  float find_mean(unsigned char test[], int size);
  
 
/**
 * * @brief returns Maximum of an array
 * 
 * This function returns the Maximum with an array of unsigned char type
 * and the SIZE as parameters.It returns an unsigned char.
 * @param Test
 * @param size
 * @return unsigned char
 */
 unsigned char find_maximum(unsigned char Test[], int size);
  
  
 /**
    * * @brief returns Minimum of an array
 * 
 * This function returns the Minimum with an array of unsigned char type
 * and the SIZE as parameters.It returns an unsigned char.
  * 
  * @param Test
  * @param size
  * @return unsigned char
  */ 
 unsigned char find_minimum(unsigned char Test[], int size);
 
 
 /**@brief Returns the array entered sorted by descent way
  * 
  *This function sorts an array of the type unsigned char and sorts it by the largest number
  * to the smallest one. It also takes SIZE as a parameter
  *  
  * @param Test
  * @param size
  * @return void
  */
  void sort_array(unsigned char Test[], int size);
 
 /**
  * @brief Prints the Median, Mean, Maximum and Minimum 
  * 
  * This function prints the Statistics(Median, Mean, Minimum, Maximum) of a given vector of
 * type unsigned char and it sorts the numbers in a descendent way. It is necesary
 * to provide the SIZE of the vector.
 * 
  * 
  * @param median
  * @param mean
  * @param minimum
  * @param maximum
  * @return void
  */
 
 void print_statistics(float median, float mean,unsigned char minimum,unsigned char maximum );
 

#endif /* __STATS_H__ */
