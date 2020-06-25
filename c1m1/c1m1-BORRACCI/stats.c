/* 
 * File:   stats.c
 * Author: Lucas Borracci
 *
 * Created on June 2, 2020, 23:25
 */

/*

 * @file <stats.c> 
 * @brief <returns statistics(Median, Mean, Maximum, Minimum). Sorts array descendent >
 *
 * This code contains 7 methods, their functions are print, find Median, find Mean, find Minimum
 *find Maximum and sort from the largest number to the shortest a specific array of the type unsigned char specifying a size
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_array(unsigned char Test[], int size);
float find_median(unsigned char Test[], int size);
float find_mean(unsigned char test[], int size);
unsigned char find_maximum(unsigned char Test[], int size);
unsigned char find_minimum(unsigned char Test[], int size);
void sort_array(unsigned char Test[], int size);
void print_statistics(float median, float mean,unsigned char minimum,unsigned char maximum );

void main() {

    /*Given Array*/
    unsigned char test[SIZE] = {34, 201, 190, 154, 8, 194, 2, 6,
        114, 88, 45, 76, 123, 87, 25, 23,
        200, 122, 150, 90, 92, 87, 177, 244,
        201, 6, 12, 60, 8, 2, 5, 67,
        7, 87, 250, 230, 99, 3, 100, 90};
  
    /* Other Variable Declarations Go Here */
    float median = 0;
    float mean = 0;
    unsigned char maximum=0;
    unsigned char minimum=0;

    /* Statistics and Printing Functions Go Here */ 
    printf("Original Array test\n");
    print_array(test, SIZE); 	//prints the inicial vector "test"

    sort_array(test,SIZE);	//sorts the array descending
    
    median = find_median(test, SIZE);  	  //calculates the median
    mean = find_mean(test, SIZE);      	 //calculates the mean
    minimum= find_minimum(test, SIZE); 	//calculates the minimum
    maximum= find_maximum(test, SIZE); //calculaates the maxumum
    
    print_statistics(median, mean,minimum,maximum); //prints statistics
    printf("--------------\n");
    printf("Sorted Array Descending\n");
    print_array(test,SIZE); 	//prints the sorted array
    
}

void print_array(unsigned char Test[], int size) {
    printf("--------------\n");
    for (int j = 0; j < size; j++) {
        printf("test[%i] = %i \n", j+1, Test[j]);
    }
}

void sort_array(unsigned char Test[], int size) {
    for (int j = 0; j < size - 1; j++) {
        for (int k = j + 1; k < size; k++) {
            if (Test[j] < Test[k]) {
                unsigned char aux = Test[k];
                Test[k] = Test[j];
                Test[j] = aux;
            }
        }
    }
}

float find_median(unsigned char Test[], int size) {
  
    //median
    int div = 0;
    int add = 0;
    float median = 0;

    if (size % 2 == 0) { //size even?
        div = size / 2;
        add = Test[div] + Test[div--];
        median = add / 2;
    } else { //odd
        div = size / 2; //only integer part
        median = Test[div + 1];
    }

    return median;
}

float find_mean(unsigned char Test[], int size) {
    int add = 0;
    for (int j = 0; j < size; j++) {
        add += Test[j];
    }
    return (add / size);
}

unsigned char find_minimum(unsigned char Test[], int size) {
    return Test[size-1];
}

unsigned char find_maximum(unsigned char Test[], int size) {
    return Test[0];
}

void print_statistics(float median,float mean, unsigned char minimum,unsigned char maximum){
    printf("--------------\n");
    printf("Statistics:\n");
    printf("Median= %f \n",median);
    printf("Mean= %f \n",mean);
    printf("Minimum= %i \n",minimum);
    printf("Maximum= %i \n",maximum);
}
