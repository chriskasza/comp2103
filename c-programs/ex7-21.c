/* 
 * File: ex7-21.c
 * Function: Rdigits
 * Purpose: compute the number of digits in the integer n
 *  (recursive solution)
 * Inputs: n (parameter)
 * Returns: number of digits in n
 * Modifies: Nothing
 * Error checking: Does nothing if n is not positive
 * Sample call:
 *    i = Rdigits(123);   
 *        i gets the value 3 
 */
int Rdigits(int n) {
	 
	if(n <= 0)
		return 0;

	if(n/10 == 0)
		return 1;

	return 1 + Rdigits(n/10);
	
}
