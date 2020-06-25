#******************************************************************************
# Created on June 21, 2020 by Lucas Borracci for Assessment c1m2
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple Makefile for multitarget build system
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#
#       build 	- Builds and links all source files and genereates:
##	c1m2.map - Map file for the full build
#	*.d      - Dependency Files for each source file
#	*.o      - Individual object files
# 	c1m2.out - Output Executable file
#
#	<FILE>.i	- Builds <FILE>.i preprocessed file.
#	<FILE>.asm	- Builds <FILE>.i assembly file.
#	<FILE>.o 	- Builds <FILE>.o object file.
#       compile-all 	- Compile all objects but do NOT link them.
#       clean 		- Removes all generated files.
#
# Platform Overrides: Conditionally assign the appropriate compiler flags,
# linker flags, and architecture flags. The target platform
# must be provided at the command line with the make
# command to set the platform you are compiling for.
#       
# PLATFORM = MSP432 - The target embedded system will use
# 			the cross compiler, arm-none-eabi-gcc.
# PLATFORM = HOST 	- The host embedded system will use the
#                     native compiler, gcc.
#
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
#General Flags (Both Platforms)
#
#   -Wall           Enable All Warning Messages (CFLAGS)
#   -Werror         Treats All Warnings as Errors(CFLAGS)
#   -g              Generate Debugging Info in Executable (CFLAGS)
#   -O0             The level of optimization (-O0, -O1, -O2, -O3)) (LDFLAGS)
#   -std=c99        The C standard set (CFLAGS)
#
#------------------------------------------------------------------------------

#Target Name
TARGET:=c1m2

COMMONCFLAGS:= -Wall -Werror -g -std=c99
COMMONLDFLAGS:= -O0 #-Map=$(TARGET).map
CPPFLAGS = -E

#*********************************************
#Compile Time Switch
ifeq ($(PLATFORM),HOST)
	#Includes header files for HOST
	INCLUDE:= -I../include/common
  
	#Includes source files for HOST
	SOURCE= main.c \
	  memory.c
  
#Compile Defines	
	CC = gcc
	LD = ld
	LDFLAGS = $(COMMONLDFLAGS) 
	CFLAGS = $(COMMONCFLAGS) -D$(PLATFORM)
	OBJDUMP = objdump
#*********************************************

else #PLATFORM MSP432
	#Includes header files for MSP432
	INCLUDE:= -I../include/common \
	   	  -I../include/msp432 \
	   	  -I../include/CMSIS

	#Includes source files for MSP432
	SOURCE= main.c  memory.c interrupts_msp432p401r_gcc.c \
		startup_msp432p401r_gcc.c system_msp432p401r.c 

	#Platform Specific Flags
	LINKERFILE = msp432p401r.lds

	#Architecture Specific Flags
	CPU= cortex-m4
	ARCH= thumb
	MARCH=armv7e-m
	MFLOAT=hard
	MFPU=fpv4-sp-d16
	SPECS=nosys.specs
  
	#Compile Defines
	CC = arm-none-eabi-gcc
	LD = arm-nome-eabi-ld
	LDFLAGS = $(COMMONCFLAGS) -T $(LINKERFILE)
	CFLAGS =  $(COMMONLDFLAGS) -D$(PLATFORM) -mcpu=$(CPU) \
		  -mthumb -march=$(MARCH) -mfloat-abi=$(MFLOAT) \
		  -mfpu=$(MFPU) --specs=$(SPECS) 

endif

#*********************************************
#Variable specifing the .o file names from the .c file names
OBJS = $(SOURCE:.c=.o)


#*********************************************
#Compiles all object files and links into a final 
#executable with the name c1m2.out
.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(LDFLAGS) $(CFLAGS) $(INCLUDE) $^ -o $(TARGET).out


#*********************************************
#Cleans all the produced files of  make
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map *.asm *.i
	rm -r $(DEPDIR)

#*********************************************
#Compile all objects but do NOT link them. 
.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) -c $(CFLAGS) $(LDFLAGS) $(INCLUDE) $^


#*********************************************
#*********************************************
#Generates all .o files from .c files (specified by -c flag)
%.o : %.c 
	$(CC) -c $(CFLAGS) $(LDFLAGS) $^ -o $@ $(INCLUDE)  

#*********************************************
#Generates the preprocessed output of all c-program implementation files. 
%.i: %.c
	$(CC) $(LDFLAGS)  $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -o $@ $^	


#*********************************************
#Create assembler file of a C source.
%.asm: %.c
	$(CC) -S $(CFLAGS) $(INCLUDE) $< -o $@
# -S flag tells the compiler just generate the assembly file


#*********************************************
#*********************************************
#This implementation places dependency files into a subdirectory named .deps.
DEPDIR := .deps

# Write the generated dependency file $(DEPDIR)/$*.d.
DEPFLAGS := -M -MT $@ -MD -MP -MF $(DEPDIR)/$*.d

# Build object files with their dependency
%.o: %.c $(DEPDIR)/%.d | $(DEPDIR)
	$(CC) $(DEPFLAGS) -c $(CFLAGS) $(INCLUDES) -o $@ $<

# Declare a rule for creating the dependency directory if it doesn’t exist.
$(DEPDIR): ; @mkdir -p $@

# Generate a list of all the dependency files that could exist.
DEPFILES := $(SOURCES:%.c=$(DEPDIR)/%.d)

# Mention each dependency file as a target, so that make won’t fail if the file
# doesn’t exist.
$(DEPFILES):










