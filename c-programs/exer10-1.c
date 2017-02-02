/*
 * Exercise 10-1
 */
#include <stdio.h>
#include <stdlib.h>
/* maxi returns the largest element in an array A of size S  */
int  maxi(int A[], int S) {
  int i;
  int m = 0;

  for(i = 0; i < S; i++) {
    if(A[i] > m) m = A[i];
  }
  return m;
}
/*
Give one example of actual parameters
 for which this function will return an incorrect result.
*/
int x[] = {-1,-2,-2};
int main() {

	  printf("%d\n", maxi(x,2));

	return EXIT_SUCCESS;
}

