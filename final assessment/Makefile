#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Author: RAFAEL-LEG
# THIS MAKE WERE MADE TO CROSS COMPILE A CODE TO ARM ARCHITECTURE AND A PC 
# ARCHITECTURE.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      	<FILE>.i
#      	<FILE>.asm
#      	<FILE>.o
#      	build
#      	compile-all
#      	clean
#
# Platform Overrides:
#      	ARM
#		PC
#
#------------------------------------------------------------------------------
include sources.mk



GFLAGS =  	-Wall \
			-g \
			-O0 \
			-std=c99 \
			-lm \
			-Werror

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d	

PLATFORM= HOST

ifeq ($(PLATFORM),MSP432)
	# Compiler Flags and Defines
	CC = 		arm-none-eabi-gcc
	LD = 		arm-none-eabi-ld

	CPU = 		cortex-m4
	ARCH = 		armv7e-m
	SPECS = 	nosys.specs
	EXTRA = 	-mthumb \
				-mfloat-abi=hard \
				-mfpu=fpv4-sp-d16

	LINKER_FILE = 		msp432p401r.lds
	LDFLAGS = 			-Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = 			$(GFLAGS) \
						-mcpu=$(CPU) \
						-march=$(ARCH) \
						$(EXTRA) \
						--specs=$(SPECS)
	CPPFLAGS = 			-DMSP432 $(INCLUDES) -DCOURSE1 -DVERBOSE
	SIZE = 				arm-none-eabi-size

endif

ifeq ($(PLATFORM),HOST)
	CC = 			gcc
	LDFLAGS = 		-Wl,-Map=c1m2.map
	CFLAGS = 		$(GFLAGS)
	CPPFLAGS = 		-DHOST $(INCLUDES) -DCOURSE1 -DVERBOSE
	SIZE = 			size
	
endif

OBJS = $(SOURCES:.c=.o)
TARGET = c1m2

#Protecting targets that is not a file name...
.PHONY: compile-all build clean

#Generate a preprocessed output file.
%.i: %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

#Generating a assembly file.
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

#Generating object file.
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

#Generating dependency file.
%.d: %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

#Generate a executable file.
build: compile-all
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(TARGET).out
	$(SIZE) $(TARGET).out
# 	$(CC) $(CFLAGS) $(SPECS) -o $(INCLUDES_PATH) $(LDFLAGS) -D $(PLATFORM) $(OBJS) $(CPPFLAGS) -o $@

#Generate compile file.
compile-all: $(OBJS)


#Delete generate file.
clean:
	rm -f src/*.i
	rm -f src/*.asm
	rm -f src/*.o
	rm -f src/*.d
	rm -f *.map
	rm -f *.out