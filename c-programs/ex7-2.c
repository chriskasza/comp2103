/* 
 * File: ex7-2.c
 * Function: digits
 * Purpose: compute the number of digits in the integer n
 * Inputs: n (parameter)
 * Returns: number of digits in n
 * Error checking: returns 0 if n is not positive
 * Sample call: i = digits(123);  
 *       i gets the value 3 
 */
int digits(int n) {
	int count = 0;
	
	if(n <= 0)
	   return 0;

	do {
		count++;
		n /= 10;
	} while(n != 0);

	return count;
}
