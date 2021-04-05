/*
 * getRegName
 *
 * This function looks up and returns the mnemonic name for a given
 * register number.
 *
 * How to call this function:
 *
 *      char * getRegName(int regNbr)
 *          Parameter: regNbr is a valid register number
 *          Pre-condition: 0 <= regNbr < 32
 *          Returns: returns a pointer to the mnemonic name associated with
 *              register number; for example: "$t0" or "$a1"
 *
 * Author: Alyce Brady, Garrett Olson, Maria Katrantzi
 * Creation Date: 2/10/1999
 * 	Modified: 5/7/2019   Added code to complete the getRegName function.
 *
 */

char *getRegName(int regNbr)
/* returns mnemonic name for given register */
{
	/* Create a static (persistent) array of the mnemonic names,
	 *    each of which is a string (char *).
	 */
	static char *regArray[] =
		{
			"$zero",
			"$at",
			"$v0", "$v1",
			"$a0", "$a1", "$a2", "$a3",
			"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
			"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
			"$t8", "$t9",
			"$k0", "$k1",
			"$gp", "$sp", "$fp", "$ra"};

	return regArray[regNbr];
}
