/******************************************************************************
 * Copyright (C) 2017 by Dineshkumar - Kumaraguru College of Technology
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Header file for stats.c
 *
 * Contains all the function declarations for the functions used in stats.c
 *
 * @author dineshkumar
 * @date 13/06/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__



/**
 * @brief prints the array
 *
 * prints the elements of the array one by one
 *
 * @param A A unsigned char array of  N-elements
 * @param N size of the array
 * 
 *
 * @return Nothing
 */
 void print_array(unsigned char A[],int N);
 
 /**
 * @brief finds the mean 
 *
 * finds the average for the given array and returns it
 *
 * @param A A unsigned char array to an N-element data array
 * @param N size of the array
 * 
 *
 * @return mean value
 */
 int find_mean(unsigned char A[],int N);
 
 /**
 * @brief finds the median 
 *
 * finds the median for the given array and returns it
 *
 * @param *A A unsigned char pointer to an N-element data array
 * @param N size of the array
 * 
 *
 * @return median value
 */
 int find_median(unsigned char A[],int N);
 
 /**
 * @brief finds the maximum
 *
 * finds the largest character for the given array and returns it
 *
 * @param *A A unsigned char pointer to an N-element data array
 * @param N size of the array
 * 
 *
 * @return The largest  value
 */
 int find_maximum(unsigned char A[],int N);
 
 /**
 * @brief finds the minimum
 *
 * finds the smallest  character for the given array and returns it
 *
 * @param *A A unsigned char pointer to an N-element data array
 * @param N size of the array
 * 
 *
 * @return The smallest value
 */
 int find_minimum(unsigned char A[],int N);


/**
 * @brief prints the array in sorted order
 *
 * prints the array in sorted order
 *
 * @param *A A unsigned char pointer to an N-element data array
 * @param N size of the array
 * 
 *
 * @return Nothing
 */
 void sort_array(unsigned char *A,int N);


#endif /* __STATS_H__ */
