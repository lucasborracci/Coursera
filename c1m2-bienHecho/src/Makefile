#******************************************************************************
# Copyright (C) 2020 by Syed Ahmad
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# makefile for two platforms ,host machine (using gcc) and MSP432P401R (using arm-none-eabi-gcc)
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#       <FILE>.o - Builds <FILE>.o object file
#       <FILE>.i - Builds <FILE>.i preprocessed file
#       <FILE>.asm - Builds <FILE>.asm assembly file
#      compile-all - compile all object files, but DO NOT link
#      build - Builds and links all source files
#      clean - removes all generated files
# Platform Overrides:
#      PLATFORM - the target platform ( HOST , MSP432 )
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

#common CFLAGS
CO_CFLAGS = -Wall -Werror -g -O0 -std=c99
TARGET = c1m2

ifeq ($(PLATFORM),HOST)
  CC = gcc
  CFLAGS = $(CO_CFLAGS)
  CPPFLAGS = -DHOST $(INCLUDES)
  LDFLAGS = -Wl,-Map=$(TARGET).map 	
  
  SIZE = size 
endif

ifeq  ($(PLATFORM),MSP432)
  # Architectures Specific Flags
  LINKER_FILE = -T msp432p401r.lds
  LINKER_FILE_PATH = -L ../
  CPU =cortex-m4 
  ARCH =armv7e-m
  SPECS =nosys.specs
  OTHER_ARCH_FLAGS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
  

  #including arch specific source files for MSP432
  SOURCES = main.c \
	  memory.c \
	  interrupts_msp432p401r_gcc.c \
	  startup_msp432p401r_gcc.c \
	  system_msp432p401r.c
  CC = arm-none-eabi-gcc
  CPPFLAGS = -DMSP432 $(INCLUDES)
  CFLAGS = $(CO_CFLAGS) $(OTHER_ARCH_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) 
  LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE_PATH) $(LINKER_FILE)

  SIZE = arm-none-eabi-size 

	
endif

  
#making variables for object files , dependency files .assembly files , preprocessed files
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PRES = $(SOURCES:.c=.i)

# using -c flag to stop before linking , so i only need CPPFLAGS & CFLAGS
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

#using -S to generate assembly file
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

#using -E to generate preprocessed file , so i only need CPPFLAGS
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

#using -E -M to generate dependency files  
%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

# compile-all will generate all object files for all source files without linking
.PHONY: compile-all
compile-all:$(OBJS)

# build will generate c1m2.map , c1m2.out ,and for each source file will generate dep. file & obj. files .
#it will also print data about memory allocation of the executable  c1m2.out 
.PHONY: build
build: $(DEPS)
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@
#clean will simply delete all files except makefile , .mk files , .c files
.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PRES) $(TARGET).out $(TARGET).map