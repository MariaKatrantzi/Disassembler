/*
 * getOpcode
 *
 * This function is used to obtain the opcode of an input binary 
 * sequence (represented as a string), and calls three seperate
 * functions to determine the instruction format type (i.e., R-format,
 * I-format, or J-format).
 * 
 * Author(s): Maria Katrantzi
 *        with assistance from: Alyce, Skylar, Josh
 *
 * Creation Date:  5/7/2019
 *   Modified: 5/10/2019   Completed functions and added documentation.
 *
 */

#include "disassembler.h"

void setRformat(int lineNum, char *string);
void setIformat(int lineNum, char *string, int opcode);
void setJformat(int lineNum, char *string, int opcode);

void getOpcode(int lineNum, char *string)
/* determine the opcode and, from that, determine the instruction format type. */
{
  int op = binToDec(string, 0, 5);

  if (op == 0)
    setRformat(lineNum, string); /* R-format */

  else if (op == 2 || op == 3)
    setJformat(lineNum, string, op); /* J-format */

  else if (op <= 43)
    setIformat(lineNum, string, op); /* I-format */

  /* otherwise print an error message for an invalid opcode */
  else
  {
    printError("Error: line %d contains an invalid opcode.\n", lineNum);
  }
}

void setRformat(int lineNum, char *string)
/* parse the instruction based on the R-format type. */
{
  /* determine fields in corresponding MIPS instruction */
  int rs = binToDec(string, 6, 10);
  int rt = binToDec(string, 11, 15);
  int rd = binToDec(string, 16, 20);
  int shamt = binToDec(string, 21, 25);
  int funct = binToDec(string, 26, 31);

  /* use an array of pointers to hold the instructions ordered by their funct */
  char *arrayR[] =
      {
          "sll", "", "srl", "", "", "", "", "", "jr", "", "",
          "", "", "", "", "", "", "", "", "", "", "", "", "", "",
          "", "", "", "", "", "", "", "add", "addu", "sub",
          "subu", "and", "or", "", "nor", "", "", "slt", "sltu"};

  char *empty = arrayR[1]; /* empty represents the null elements within the array */
  char *instr = arrayR[funct];

  /* print the different combinations of valid instructions and registers */
  if (funct == 8 && rt == 0 && rd == 0 && shamt == 0)
  {
    char *rName1 = getRegName(rs);
    printf("%s\t %s\n", instr, rName1);
  }

  else if (shamt != 0 && rs == 0 && (funct == 0 || funct == 2))
  {
    char *rName2 = getRegName(rd);
    char *rName3 = getRegName(rt);
    printf("%s\t %s, %s, %d\n", instr, rName2, rName3, shamt);
  }

  else if (instr != empty && instr != NULL && shamt == 0 && funct != 0 && funct != 2 && funct != 8)
  {
    char *rName4 = getRegName(rd);
    char *rName5 = getRegName(rs);
    char *rName6 = getRegName(rt);
    printf("%s\t %s, %s, %s\n", instr, rName4, rName5, rName6);
  }

  /* otherwise print an error message if the instruction is invalid */
  else
  {
    printError("Error: line %d is invalid MIPS R-format instruction.\n", lineNum);
  }
}

void setIformat(int lineNum, char *string, int opcode)
/* parse the instruction based on the I-format type. */
{
  /* determine fields in corresponding MIPS instruction */
  int rs = binToDec(string, 6, 10);
  int rt = binToDec(string, 11, 15);
  int immediate = binToDec(string, 16, 31);

  /* use an array of pointers to hold the instructions ordered by their funct */
  char *arrayI[] =
      {
          "", "", "", "", "beq", "bne", "", "", "addi", "addiu", "slti",
          "sltiu", "andi", "ori", "", "lui", "", "", "", "", "", "", "", "", "",
          "", "", "", "", "", "", "", "", "", "",
          "lw", "", "", "", "", "", "", "", "sw"};

  char *empty = arrayI[0]; /* empty represents the null elements within the array */
  char *label = arrayI[opcode];

  /* print the different combinations of valid instructions and registers */
  if (opcode == 15 && rs == 0)
  {
    char *rName7 = getRegName(rt);
    printf("%s\t %s, %d\n", label, rName7, immediate);
  }

  else if (opcode == 35 || opcode == 43)
  {
    char *rName8 = getRegName(rt);
    char *rName9 = getRegName(rs);
    printf("%s\t %s, %d(%s)\n", label, rName8, immediate, rName9);
  }

  else if (opcode == 4 || opcode == 5)
  {
    char *rName10 = getRegName(rs);
    char *rName11 = getRegName(rt);
    int newimm = immediate * 4;
    printf("%s\t %s, %s, %d\n", label, rName10, rName11, newimm);
  }

  else if (label != empty && label != NULL && opcode != 15)
  {
    char *rName12 = getRegName(rt);
    char *rName13 = getRegName(rs);
    printf("%s\t %s, %s, %d\n", label, rName12, rName13, immediate);
  }

  /* otherwise print an error message if the instruction is invalid */
  else
  {
    printError("Error: line %d is invalid MIPS I-format instruction.\n", lineNum);
  }
}

void setJformat(int lineNum, char *string, int opcode)
/* parse the instruction based on the J-format type. */
{
  /* determine fields in corresponding MIPS instruction */
  int address = binToDec(string, 6, 31);
  int newadd = address * 4; /* multiple by 4 to get the address associated with the specified label */

  /* print the different combinations of valid instructions */
  if (opcode == 2)
  {
    char *call1 = "j";
    printf("%s\t %d\n", call1, newadd);
  }

  else if (opcode == 3)
  {
    char *call2 = "jal";
    printf("%s\t %d\n", call2, newadd);
  }

  /* otherwise print an error message if the instruction is invalid */
  else
  {
    printError("Error: line %d is invalid MIPS I-format instruction.\n", lineNum);
  }
}
