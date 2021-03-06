# A simple makefile

GCC=gcc -Wall -Wextra -Wpedantic -Wformat -Wshadow -Wredundant-decls \
    -Wstrict-prototypes
# Can also use -Wtraditional or -Wmissing-prototypes

# When you just run `make` without specifying a target, it looks for a
# target called `all`.
#  Switch to the second, alternative version of the "all" target
#  when you're ready to compile the disassembler project.

all:	 disassembler

testArgs:	disassembler.h \
		same.h \
    		printFuncs.h \
    		process_arguments.h \
		process_arguments.c \
		printDebug.c \
		printError.c \
		disUtilDriver.c
		$(GCC) process_arguments.c printDebug.c printError.c \
		    disUtilDriver.c -o testArgs

disUtil:	disassembler.h \
		same.h \
    		printFuncs.h \
    		process_arguments.h \
		process_arguments.c \
    		verifyMIPSInstruction.c \
		binToDec.c \
		printDebug.c \
		printError.c \
		disUtilDriver.c
		$(GCC) process_arguments.c printDebug.c printError.c \
		    verifyMIPSInstruction.c binToDec.c \
		    disUtilDriver.c -o disUtil

# Alyce will test your utility functions with her own main.
alyce:	disUtil alyceMain.c
	$(GCC) process_arguments.c verifyMIPSInstruction.c binToDec.c \
	    printDebug.c printError.c alyceMain.c -o disUtil

# The assembler will probably have other source files in addition to these.
# Be sure to include them in the list of dependencies below and also in the
# $(GCC) compilation command immediately following the dependencies.
disassembler:	disassembler.h \
		same.h \
    		printFuncs.h \
    		process_arguments.h \
		process_arguments.c \
    		verifyMIPSInstruction.c \
		binToDec.c \
		getRegName.c \
		printDebug.c \
		printError.c \
		getOpcode.c \
		disassembler.c
		$(GCC) process_arguments.c verifyMIPSInstruction.c binToDec.c \
		    getRegName.c \
			getOpcode.c \
		    printDebug.c printError.c disassembler.c -o disassembler

clean: 
	rm -rf *.o disUtil disassembler
