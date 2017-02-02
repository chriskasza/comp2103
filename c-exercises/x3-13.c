/*
 * Exercise 3-13
 * Program to find the area of a rectangle. This program should prompt 
 * the user to enter the values of both sides, perform basic error checking and 
 * output the area (use the "Read Two Integers" idiom and add a prompt). If the 
 * input is incorrect, the program should output a message, and exit.
 */
#include <stdio.h>
#include <stdlib.h>
int main()  {
   double side1;
   double side2;

   printf("Enter the sides of a rectangle: ");
   if(scanf("%lf%lf", &side1, &side2) != 2 || side1 <= 0 || side2 <= 0 )  { 
      fprintf(stderr, "Error encountered reading\n");
      return EXIT_FAILURE;
   }
   
   printf("Area = %f\n", side1 * side2);
  
   return EXIT_SUCCESS;
}
