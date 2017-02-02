/*
 * Exercise 4-9
 * Program that keeps on reading integer values from the standard input stream
 * (include a prompt). It should read three integer values in a single read 
 *  operation, and every time the
 * three values have been successfully read, output the sum of these values. 
 *  If less than three values have
 *  been successfully read, the program should output the appropriate message.
 *  The program should terminate
 * when no values have been successfully read. Describe the boundary cases for this program.
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
   int one, two, three;

   while(1) {

      printf("Enter three integer values\n");
      switch(scanf("%d%d%d", &one, &two, &three)) {
      case EOF:
      case 0:
                  return EXIT_SUCCESS;

      case 1:     printf("only one value read: %d\n", one);
                  /* skip one offending character */
                  getchar();
                  /* boundary case (below); (1): one value waiting */
                  printf("Enter two more integer values\n");
                  switch(scanf("%d%d", &two, &three)) {
                  case 0:
                  case EOF: 
                            printf("nothing read\n");
                            getchar();
                            continue;
                  case 1:
                            printf("one value correct: %d, skipping to end of line\n", two);
                            while(getchar() != '\n')
                                  ;
                            continue;
                   case 2:  /* OK */
                            printf("sum of %d, %d, %d = %d\n", one, two, three, one + two + three);
                            break;
                  }
      case 2:     
                  /* skip one offending character */
                  getchar();
                  /* boundary case (below); (2) or (3): no value waiting */
                  printf("two values read: %d and %d\n", one, two);
                  printf("Enter one more value: ");
                  if(scanf("%d", &three) != 1) {
                     printf("Nothing read, skipping to end of line\n");
                     while(getchar() != '\n')
                         ;
                     continue;
                  } 
                  printf("sum = %d\n", one + two + three);

      case 3:     printf("sum of %d, %d, %d = %d\n", one, two, three, one + two + three);
                  break;

      default:    fprintf(stderr, "this can not happen\n");
                  return EXIT_FAILURE;
      }
   }

   return EXIT_SUCCESS;
}

/* Boundary cases:
 *    ^D (end-of-file) encountered
 *    values read:
 *    (1)       1 2 a
 *    (2)       1 b 3
 *    (3)       1 b c
 *    (4)       c 1 3
 *           c d 4
 *           1 4 6
 */
 
