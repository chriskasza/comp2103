/*
 * File: ex4-1.c
 * Program that demonstrates the use of gotos.
 * Finds the sum of all positive numbers and the
 * sum of negative numbers individually, as well
 * as the sum of both. Stops when it encounters zero.
 * For example: 5 3 -4 5 -2 1 0 would give the result:
 *        Total: 8
 *         Postitive: 14
 *         Negative: -6
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
     int count, n, sum, sumPos, sumNeg;

     sum = sumPos = sumNeg = count = 0;
     printf("Enter integer values, to stop enter 0\n");
  loop:
     scanf("%d", &n);
     if (n == 0)
          goto print;
     count++;
     if (n < 0)
          goto negn;
     sumPos += n;
     goto cont;
  negn:
     sumNeg += n;
  cont:
     sum += n;
     goto loop;
  print:
     if(count == 0) 
	printf("No values have been entered\n");
     else {
	printf("%d values have been entered\n", count);
	printf("The total sum is %d\n", sum);
	printf("The sum of positives is %d\n", sumPos);
     	printf("The sum of negatives is %d\n", sumNeg);
     }

     return EXIT_SUCCESS;
}
