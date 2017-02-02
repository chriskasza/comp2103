/*
 * File: x11-21main.c
 * Application of the module implementing homogenous lists. The menu-driven
 *	program tests all operations provided by the module.
*/

#include <stdlib.h>
#include <stdio.h>
#include "x11-21list.h"

/*
 * Function: menu
 * Purpose:  to display the meny
 */
void menu(){
	printf("Operations available : \n");
	printf(" Enter c for create list \n");
	printf(" Enter r to read list from a file \n");
	printf(" Enter w to write list to a file \n");
	printf(" Enter d to display element\n");
	printf(" Enter a to append element to a list \n");
	printf(" Enter m to see the menu \n");
	printf(" Enter x to remove Element from a list \n");
	printf(" Enter f to destruct list \n");
	printf(" Enter q to quit \n");
}

int main( ) {
	int done = 0;
	char choice, name[100];
	char res;
	int size, ele1, ele2, ele3;

	menu();
	while (!done) {
		printf("Enter your selection ( m to see the menu)\n");
		scanf("%c", &choice);
		
		/* skip remainder of the line */
		while( getchar() != '\n')
					;

		switch( choice ){
			case 'c': 	/* construct the list */
				while(1) {
					printf("Enter the size of the list > ");
					if( scanf("%d", &size) != 1){
						printf("Incorrect format: try again! \n");
						while( getchar() != '\n') 
                                                  ;
					}
					else break;
				}
				while( getchar() != '\n') 
                                     ;
				if( constructList( size ) )
					printf("Success : list constructed ! \n");
				else{
					fprintf(stderr,"Fatal error \n");
					return EXIT_FAILURE;
				}
				break;
			case 'r':  /* read text file into list */
				while(1) {
					printf("Enter the name of the file to read list from >  \n");
					if( scanf("%s", name) != 1){
						printf("Incorrect input, try again \n");
						while( getchar() != '\n') 
                                                  ;
					}
					else break;
				}
				while( getchar() != '\n') 
                                      ;
				res = readFile( name );
				if(  res == 0 ){
					printf("Fatal error \n");
					return EXIT_FAILURE;
				}
				else printf("List created \n");
				break;
			case 'w':  /* write list to file */
				while(1) {
                                  printf("Enter the name of the file to write list to >  \n");
                                  if( scanf("%s", name) != 1){
                                     printf("Incorrect input, try again\n");
                                     while( getchar() != '\n') 
                                       ;
                                  }  
                                  else break;
                               }  
                               while( getchar() != '\n') 
                                      ;
                               res = writeFile( name );
                               if(  res == 0){
                                  printf("Fatal error\n");
                                  return EXIT_FAILURE;
                               }  
                               else printf("List written\n");
				break;
			
			case 'a':  /* add values to list */
			     while(1) {
                                 printf("Enter 3 integers to add as a list element list > ");
                                 if( scanf("%d%d%d", &ele1, &ele2, &ele3) != 3){
                                    printf("Incorrect format: try again!\n");
                                    while( getchar() != '\n') 
                                         ;
                                 }
                                 else break;
                              }
                              while( getchar() != '\n') 
                                      ;
                              if( appendEle( ele1, ele2, ele3 ) )
                                 printf("Success : element added !\n");
                              else
                                 fprintf(stderr, "unable to add element\n");
                              break;
			 case 'x':   /* remove first element from the list */
				if( removeFirstEle() )
                                  printf("Success : element removed !\n");
                               else
                                  fprintf(stderr,"unable to remove element\n");
                               break;

			 case 'd':   /* display element from the list */

			     while(1) {
                                 printf("Enter a position in the list > ");
                                 if( scanf("%d", &ele1) != 1){
                                    printf("Incorrect format: try again!\n");
                                    while( getchar() != '\n') 
                                         ;
                                 }
                                 else break;
                              }
                              while( getchar() != '\n') 
                                      ;
				 showEle(ele1); 
                               break;
			 case 'f':   /* destruct the list */
                               if( destructList() )
                                  printf("Success : list killed!\n");
                               else
                                  fprintf(stderr, "unable to kill list\n");
                               break;

			case 'm': 
				menu();
				break;
			case 'q': 
				done = 1;
				break;
			default:
				printf("Incorrect choice, try again !\n");
				menu();
		}
	}	

	return EXIT_SUCCESS;
}

