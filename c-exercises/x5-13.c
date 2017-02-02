/*
 * Exercise 5-13
 * A menu-driven program that can be used to test your knowledge of addition, 
 * subtraction, and
 * multiplication. For addition and subtraction, limit input values to 
 * those less than 100, for multiplication,
 * limit input values to those less than 10. The program should display a 
 * message if an incorrect value has been entered, and then it should terminate, 
 * displaying the number of correct answers and
 * the number of incorrect answers (also, add an exit option 
 * to the menu that allows the user to exit from the program). 
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
   const int LIMIT = 100;
   const int MLIMIT = 10;
   int correct = 0;
   int incorrect = 0;
   int i;
   double a, b, r;

   while(1) {
      printf("Enter your option (h for help)\n");
      if((i = getchar()) == EOF)
         break;
      /* skip until end of line */
      while(getchar() != '\n')
         ;
      switch(i) {
      case 'a': printf("Enter two values (less than %d) and their sum\n", LIMIT);
                if(scanf("%lf%lf%lf", &a, &b, &r) != 3 || a >= LIMIT || b >= LIMIT) {
                   printf("%d correct answers and %d incorrect answers\n",
                           correct, incorrect);
                   return EXIT_FAILURE;
                }
                /* skip until end of line */
                while(getchar() != '\n')
                   ;
                if(a + b == r) {
                   printf("Correct\n");
                   correct++;
                } else {
                   printf("Incorrect\n");
                   incorrect++;
                }
                break;
      case 's': printf("Enter two values (less than %d) and their difference\n", LIMIT);
                if(scanf("%lf%lf%lf", &a, &b, &r) != 3 || a >= LIMIT || b >= LIMIT) {
                   printf("%d correct answers and %d incorrect answers\n",
                           correct, incorrect);
                   return EXIT_FAILURE;
                }
                /* skip until end of line */
                while(getchar() != '\n')
                   ;
                if(a - b == r) {
                   printf("Correct\n");
                   correct++;
                } else {
                   printf("Incorrect\n");
                   incorrect++;
                }
                break;
      case 'm': printf("Enter two values (less than %d) and their product\n", MLIMIT);
                if(scanf("%lf%lf%lf", &a, &b, &r) != 3 || a >= MLIMIT || b >= MLIMIT) {
                   printf("%d correct answers and %d incorrect answers\n",
                           correct, incorrect);
                   return EXIT_FAILURE;
                }
                /* skip until end of line */
                while(getchar() != '\n')
                   ;
                if(a * b == r) {
                   printf("Correct\n");
                   correct++;
                } else {
                   printf("Incorrect\n");
                   incorrect++;
                }
                break;
      case 'h': printf("Enter a for addition, s for subtraction, m for multiplication, q to quit\n");
                break;
      case 'q': printf("%d correct answers and %d incorrect answers\n",
                           correct, incorrect);
                return EXIT_SUCCESS;
      default:  printf("wrong option\n");
      }
   }  
          
   return EXIT_SUCCESS;
}
 
