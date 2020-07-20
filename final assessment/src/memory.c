/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/*Functions added for final assessment**************************/
/***************************************************************/
/*The function handles overlaping*/
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){

  uint8_t *srcRes;
  srcRes = (uint8_t*) calloc(length, sizeof (uint8_t)); /*reserves some space in memory*/
  uint8_t *inPosSrcRes;
  inPosSrcRes = srcRes; /*saves initial position of srcRes*/

  for (int i = 0; i < length; i++) {
      *srcRes = *src;
      src++;
      srcRes++;
  }
    
  uint8_t *inPosDst;
  inPosDst = dst; /*saves initial position of dst*/
  srcRes = inPosSrcRes; /*reset position of srcRes*/

  for (int i = 0; i < length; i++) {/*copies the data from srcRes to dst*/
      *dst = *srcRes;
      dst++;
      srcRes++;
  }
   
  return (inPosDst); /*returns a pointer to the  destination*/
}

/*--------------------------------------------------------------*/
/*The funtion does not handle overlaping*/
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  
  uint8_t *inPosDst;
  inPosDst = dst; /*saves initial position of dst*/
  
  for (int i=0;i<length;i++)
  {
    *dst=*src;/*copies src to dst */
    dst++;
    src++;
  }

  return(inPosDst); /*returns a pointer to the destination*/
}

/*--------------------------------------------------------------*/
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  uint8_t *inPos; /*saves initial position of src*/
  inPos = src;
  for (int i=0;i<length;i++)
  {
    *src=value; /*sets the content of src to value*/
    src++;
  }
  return(inPos);  /*returns initial position of src*/	
}

/*--------------------------------------------------------------*/
uint8_t * my_memzero(uint8_t * src, size_t length){
  
  uint8_t *inPos; /*saves initial position of src*/
  inPos = src;
  for (int i=0;i<length;i++){/*sets to 0 all the content*/
    *src=0;
    src++;  
  }	
  return(inPos); /*returns initial position of src*/
}

/*--------------------------------------------------------------*/
uint8_t * my_reverse(uint8_t * src, size_t length){
  
  uint8_t *inPosSrc;
  inPosSrc=src; /*initial position for src*/
    
  uint8_t *srcReserved;
  srcReserved=(uint8_t*)calloc(32,sizeof(uint8_t));/*reserves some memory o copy the data*/

  for (int i=0;i<length;i++)/*copies the data to the memory allocated in calloc (srcReserved)*/
  {
    *srcReserved=*src;
    src++;
    srcReserved++;
  }
  srcReserved--;
  src=inPosSrc; /*sets src to its initial position*/
  
  for(int i=0;i<length;i++)/*copies the array backwards*/
  {
    *src=*srcReserved; /*initial pos of src, final position on srcReserved*/
    src++;
    srcReserved--;
  }
  src=inPosSrc; /*sets src to its initial position*/
  return(src);  /*returns the pointer to the source*/
}

/*--------------------------------------------------------------*/
/*length is the number of words to allocate in memory*/
int32_t * reserve_words(size_t length){ /*A word is 32bits length (4 x uint8_y) in this case.*/
  
  int32_t*ptr; /*variable of the type that will return the function calloc*/
  ptr = (int32_t*)calloc(length,sizeof(int32_t));/*a casting is done for converting the null pointer to a int32_t pointer*/
  return(ptr);/*returns a pointer to the first word of the allocated memory*/
}

/*--------------------------------------------------------------*/
void free_words( uint32_t* src){
    free( src );
    return;
}






















