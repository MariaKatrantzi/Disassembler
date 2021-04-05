/*
 * Test Driver to test verifyMIPSInstruction, and getOpcode function.
 *
 * This program reads lines from a file. For each line, the program
 * calls verifyMIPSInstruction.  If the line contains characters
 * representing a valid MIPS instruction, the program calls getOpcode
 * and prints a valid MIPS instruction or an error for each line. 
 *
 * Usage:
 *          name [ filename ] [ 0|1 ]
 *      where "name" is the name of the executable, "filename" is an
 *      optional file containing the input to read, and " 0" or
 *      "1" specifies that debugging should be turned off or on,
 *      respectively, regardless of any calls to debug_on, debug_off,
 *      or debug_restore in the program.  Both arguments are optional;
 *      if both are present they may appear in either order.  If no
 *      filename is provided, the program reads its input from stdin.
 *      If no debugging choice is provided, the program prints debugging
 *      messages, or not, depending on indications in the code.
 *
 * Input:
 *      The program reads its input from a file passed in as a parameter
 *      on the command line, or reads from the standard input. Refer to
 *      the "TestCases.md" file for a detailed description of the program's
 *      test cases.
 *
 * Output:
 *      For each valid line, the program prints a valid MIPS instruction
 *      that contains the final mnemonics, including appropriate punctuation.
 *      Otherwise, the program prints an error message that briefly describes
 *      the type of error the program encountered. 
 * 
 * Author(s): Maria Katrantzi
 *
 * Creation Date:  5/7/2019
 *   Modified: 5/10/2019   Completed main function and added documentation.
 *
 */

#include "disassembler.h"

const int SAME = 0; /* useful for making strcmp readable */

int main(int argc, char *argv[])
{
    FILE *fptr;          /* file pointer */
    char buffer[BUFSIZ]; /* place to store line that is read in */
    int length;          /* length of line read in */
    int lineNum = 0;     /* keep track of input line numbers */

    /* Process command-line arguments -- input file name
     *    and/or debugging indicator (1 = on; 0 = off).
     */
    fptr = process_arguments(argc, argv);
    if (fptr == NULL)
    {
        return 1; /* Fatal error when processing arguments */
    }

    while (fgets(buffer, BUFSIZ, fptr)) /* fgets returns NULL if EOF */
    {
        lineNum++;

        /* If the last character in the string is a newline, "remove" it
         * by replacing it with a null byte. 
         */
        length = strlen(buffer);
        if (buffer[length - 1] == '\n')
            buffer[--length] = '\0'; /* remove; pre-decrement length */
        if (buffer[length - 1] == '\r')
            buffer[--length] = '\0'; /* remove; pre-decrement length */
        printDebug("Length: %d\n", length);

        /* Verify that the string is a valid binary sequence. */
        if (verifyMIPSInstruction(lineNum, buffer) == 1)
        {
            getOpcode(lineNum, buffer); /* test getOpcode function */
        }
    }
    /* End-of-file encountered; close the file. */
    fclose(fptr);
    return 0;
}
