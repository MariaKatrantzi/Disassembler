/*
 * binToDec
 *
 * This function converts the binary digits from string[begin] to
 * string[end] to a decimal integer.
 *
 * int binToDec(char string[], int begin, int end)
 *   Pre-condition:  begin and end are valid indices in array string;
 *   		     every character from string[begin] to string[end]
 *		     (including those two) has a character value '0' or '1'
 *   Returns: the decimal equivalent of the binary number represented by
 *	      the characters in string[begin] - string[end].
 *            (If begin > end, this function arbitrarily returns 0.)
 *
 * For example, assume A is a character array that contains the
 *    following characters:
 *            '1'  '0'  '1'  '1'  '0'  '1'  '0'  '0'  '1'
 *    The call binToDec(A, 2, 5) converts the binary number 1101
 *    (represented by the substring A[2] - A[5]) to the decimal integer
 *    13 and returns it.
 * 
 * Note: The decimal value returned may appear to be negative if the
 * string being converted is long enough (end - begin + 1 == 32)
 * and if the first character is '1'.
 *
 * Implementation:
 *	This function works by using simple methods such as for loops, if statements,
 *  pointer arithmetic and left bit shift. 
 *
 * Author:  Maria Katrantzi, Anderson Gonzalez
 *	with assistance from: Tim Rutledge, Alyce
 *
 * Creation Date:  April 08, 2019 
 *	modified: April 09, 2019 to complete function.
 *	modified: April 09, 2019 finished fuction and added documentation.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int binToDec(char *string, int begin, int end)
{

  int slength = end - begin + 1; /*lenght of substring */

  /* Uses malloc function to allocate space for the substring */
  char *dest = (char *)malloc(sizeof(char) * (slength + 1));

  int i;

  for (i = begin; i <= end && (*string != '\0'); i++) /* Copies char from input string to substring */
  {
    *dest = *(string + i);
    dest++;
  }

  *dest = '\0'; /* adds the null byte to end of the substring */

  int count = 0;

  dest--; /* moves pointer to char before nullptr */

  int j;

  /* converts substring from binary to decimal number */
  for (j = 0; j < slength; j++)
  {
    if (*dest == '1')
    {
      count += 1 << j; /* multiplies 1 by the appropriate power of two */
    }
    dest--;
  }

  return count; /* retuns decimal number */
}
