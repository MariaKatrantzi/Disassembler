/*
 * verifyMIPSInstruction
 *
 * This function verifies that the string provided to it as a paramater
 * contains 32 characters representing binary digits (characters '0' and
 * '1'), followed by a null byte.  If the string contains the wrong
 * number of characters or contains invalid charaters (not '0' or '1'),
 * then the function prints an error message to stderr giving the line
 * number and an appropriate error message.
 *
 *   int verifyMIPSInstruction (int lineNum, char *instruction);
 *
 *	    Pre-condition:  instruction is a null-terminated string
 *	    Post-condition: the characters in "instruction" have not
 *			    been modified
 *	    Returns: 1 if instr contained 32 characters representing binary
 *			    digits ('0' and '1') followed by a null byte
 *		     0 if instr has the wrong number of characters or
 *		            contains invalid characters
 *	    Output: Prints an error message to stderr if necessary
 *
 * Implementation:  
 *	This function works by using simple methods such as for loops, if statements 
 * and pointer arithmetic. 
 *
 * Author: Maria Katrantzi , Anderson Gonzalez
 *	with assistance from: Tim Rutledge, Alyce
 *
 * Creation Date:  April 08, 2019
 *	
 */

#include "disassembler.h"
#include <stdio.h>
#include <string.h>

static const int INSTR_LENGTH = 32;

int verifyMIPSInstruction(int lineNum, char *instr)
{

  int length = strlen(instr); /* length of input string */

  if (length != INSTR_LENGTH) /* print error if length not INSTR_LENGTH */
  {
    printError("Error: line %d does not have %d chars.\n", lineNum, INSTR_LENGTH);
    return 0;
  }

  int discount = 0; /* Counter for '0' and '1' char */

  while (*instr != '\0')
  {
    if (*instr == '0' || *instr == '1')
      discount++;

    instr++;
  }

  if (discount == INSTR_LENGTH) /* returns 1 if discount = INSTR_LENGTH */
    return 1;

  else /* prints Error message if there are none 1 or 0 char */
    printError("Error: line %d does not contain all 0's or 1's.\n", lineNum);

  return 0;
}
