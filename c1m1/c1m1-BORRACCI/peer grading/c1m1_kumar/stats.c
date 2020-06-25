
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
 * @file stats.c
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author Dineshkumar
 * @date 13/06/2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
   //print_array(test,40);
   int b = find_mean(test,40);
   printf("Mean : %d ",b);
   int c = find_median(test,40);
   printf("\nMedian : %d ",c);
   int q = find_minimum(test,40);
   printf("\nMinimum : %d",q);
   
   int q1 = find_maximum(test,40);
   printf("\nMaximum : %d",q1);
   
   sort_array(test,40);
   
   print_array(test,40);
  

}

void print_array(unsigned char A[],int N)
{
    printf("\nArray : ");
    for(int i=0;i<N;i++)
    {
        printf("%d ",A[i]);
    }
    
}

int find_mean(unsigned char A[],int N)
{
    int T=0;
    for(int i=0;i<N;i++)
    {
        T=T+A[i];
     
    }
    return T/N;
    
}

int find_median(unsigned char A[],int N)
{
    int c =0;
    int d =N/2;
    if(N%2 == 0)
    { 
      c=(A[d-1]+A[d])/2;
      return c;
    }
    else
    {
        return A[d];
    }
    
}

int find_minimum(unsigned char A[],int N)
{
    int min = 255;
    for(int i=0;i<N;i++)
    {
        if(A[i]<min)
          min = A[i];
    }
    
    return min;
}

int find_maximum(unsigned char A[],int N)
{
    int max=0;
    for(int i=0;i<N;i++)
    {
        if(A[i]>max)
          max = A[i];
    }
    
    return max;
}

void sort_array(unsigned char *ptr,int n) 
{ 
    int i, j;
    unsigned char t = 0;
  
    for (i = 0; i < n; i++) { 
  
        for (j = i + 1; j < n; j++) { 
  
            if (*(ptr + j) < *(ptr + i)) { 
  
                t = *(ptr + i); 
                *(ptr + i) = *(ptr + j); 
                *(ptr + j) = t; 
            } 
        } 
    } 
}
/* Add other Implementation File Code Here */
