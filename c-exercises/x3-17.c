/*
 * Exercise 3-17
 * The other day I went to the bank to cash a cheque for $5.89. I asked the 
 * cashier to give me as few coins as possible. She did not have any dollar 
 * coins; instead she gave me quarters (25c), dimes (10c), nickels (5c) and 
 * pennies (1c). How many of each kind of coin did I get? Write a program that 
 * inputs the value in dollars and outputs the type of each coin, and the 
 * number  of the types of this coin. Assume that the cashier does not have any 
 * coins larger than a quarter, and that she always gives the minimum number of 
 * of coins possible. For example, given 46 cents, the program outputs: 1 
 * quarter, 2 dimes, 1 penny. 
 */
#include <stdio.h>
#include <stdlib.h>
int main(){ 
   int amount;
   int quarters = 0;
   int dimes = 0;
   int nickels = 0;
   int pennies = 0;
   int leftOver;

   printf("Enter amount in cents (e.g. 589 not 5.89): ");
   if(scanf("%d", &amount) != 1 || amount < 0 )  {
      fprintf(stderr, "Error encountered reading\n");
      return EXIT_FAILURE;
   }
    
   quarters = amount/25;
   leftOver = amount%25;

   dimes = leftOver/10;
   leftOver = leftOver%10;

   nickels = leftOver/5;
   leftOver = leftOver%5;

   pennies = leftOver;

   printf("%d quaters %d dimes %d nickels %d pennies\n",quarters, dimes, nickels, pennies);

   return EXIT_SUCCESS;
}
