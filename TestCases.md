 #TestCases 

 VERSION or DATE: 10 May 2019

 AUTHORS: Maria Katrantzi
  
  The input file "testdisassembler.txt" includes sufficient test cases to check the 
 correctness of the functions we implemented in the verifyMIPSInstruction.c and
 getOpcode.c file. 

 In increasing order, the test cases chech the program output given:

 1-12) R-format instructions
 13-23) I-format instructions
 24-25) J-format instructions
 26) empty string
 27) a string of length 1
 28) too short string
 29) too long string
 30) a char other than 0/1 at the first bit
 31) a char other than 0/1 at the last bit
 32,34) valid characters at both extremities
 33) invalid opcode (44 in decimal)
 35) invalid funct (41 in decimal)
 36) invalid funct (50 in decimal)
 37) invalid shamt (4 in decimal)
 38) invalid funct (1 in decimal), format similar to "sll"
 39) invalid rd (1 in decimal), format similar to "jr"
 40) invalid opcode (6 in decimal)
 41) invalid rs (4 in decimal), format similar to "lui"

