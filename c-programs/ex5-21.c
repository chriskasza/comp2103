/*
 * File: ex5-21.c
 * Copies a single line from the keyboard and redisplays it. Tests for eof
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
     int c;

     while ((c = getchar()) != '\n')
	if(c == EOF)
		break;
        else putchar(c);
     if(c != EOF)
	putchar(c);              

     return EXIT_SUCCESS;
}

