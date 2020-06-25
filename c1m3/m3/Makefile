#*************************************************************
#Author: Lucas Borracci	
#Created on July 23, 2020
#*************************************************************

#-------------------------------------------------------------
#Makefile for c1m3
#-------------------------------------------------------------

SOURCES = main.c misc.c

TARGET = c1m3

CC = arm-none-eabi-gcc
CFLAGS = -Wall -Werror -g -O0 -std=c99
LINKER_FILE =-T msp432p401r.lds
LDFLAGS = -Wl,-Map=main.map $(LINKER_FILE)

#List the symbols from object files
#NM = arm-none-eabi-nm 

#SIZE = arm-none-eabi-size

#Variable for object files
OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.asm)

#Creating object files from c files,-c stop before linking
%.o : %.c
	$(CC) -c $^ -I  $(CFLAGS) -o $@

#Creating .asm files from .c files
%.asm : %.c
	$(CC) -S $^ -I  $(CFLAGS) 

#Objects: will deliver all .o files and .map file
.PHONY: objects
compile:$(OBJS)

#Asm: will deliver all .asm files and .map files
.PHONY: asm
asm:$(ASMS)


#Build: will deliver the output c1m3.out, .asm and .o
.PHONY: build
build:$(OBJS)
build:$(ASMS)
build:$(TARGET).out

$(TARGET).out : $(OBJS)
	$(CC) $(LDFLAGS) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(ASM) $(TARGET).out main.map main.s misc.s
