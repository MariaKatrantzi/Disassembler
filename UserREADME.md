PROJECT TITLE: Disassembler Programming Project

PURPOSE OF PROJECT: Write a program that will read in machine language
and write out the corresponding assembly language commands.

VERSION or DATE: 10 May 2019

HOW TO START THIS PROJECT: Open the dissasembler project within your text
editor. Use the "disassembler.c" and "testdisassembler.txt" file to change
the output of the project.

AUTHORS: Maria Katrantzi

USER INSTRUCTIONS: To run the program, run "make" and "./disassembler 
testdisassembler.txt" on the terminal line.

For a sample Input, consider the following machine code:
00000000010000110000100000100000
00000000010000110000100000100001
00000000010000110000100000100010

The corresponding Output has the following form:
add      $at, $v0, $v1
addu     $at, $v0, $v1
sub      $at, $v0, $v1