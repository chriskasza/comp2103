/*
 * File: ex11-2-List-main1.c
 * Application of the module List that implements dynamic lists of characters
 * The menu driven program to test List
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ex11-2-list.h"
#include "ex11-enum.h"
/* Callback functions */
DataType copyData_List(const DataType v) {
	return strdup(v);
}

void freeData_List(DataType v) {
	free(v);
}

/* Displays available commands */
void help() {
    printf("This is a list of char* values. You can create up to 5 list\n");
    printf("and up to 5 enumerations. Enter\n");
    printf("\th for help\n");
    printf("\tc to construct an list\n");
    printf("\ti to insert the element of the list\n");
    printf("\tx to delete an element of the list\n");
    printf("\tl to show the length of the list\n");
    printf("\te to construct an enumeration\n");
    printf("\tm to test if there are more elements in enumeration\n");
    printf("\tn to get the next element in enumeration\n");
    printf("\tp to prints all elements using enumeration\n");
    printf("\tk to destruct the enumeration\n");
    printf("\td to destruct the list\n");
    printf("\tQ to quit\n");
}

#define SKIP      while(getchar() != '\n');
#define SIZE 20	/* maximum size of a string */

/* reads in user's command and executes the corresponding command */
void menu() {
	int c, i;
	int number;  /* initial size */
	DataType pc;
	char buffer[SIZE+1];
	Abstract_List col[SIZE];	/* five lists */
	Abstract_Enumeration enu[SIZE];	/* five enumerations */
	void *p;

  for(i = 0; i < SIZE; i++)   { /* initialize the lists */
	enu[i] = NULL;
	col[i] = NULL;
  }
  while(1) {
	printf("> (h for help): ");
	c = getchar();
	SKIP

	switch (c) {
	case 'h':
	case 'H':
		help();
                break;
	case 'c':
	case 'C':	
	      printf("Enter list # (between 0 and 4): ");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid values\n");
			SKIP
			break;
		}
		SKIP
		if((col[i] = construct_List()) == NULL)
			fprintf(stderr, "can't initialize\n");
		break;
	case 'i':
	case 'I':
		printf("Enter list # (between 0 and 4)\nthe position and a string to be inserted\n");
		if(scanf("%d%d%s", &i, &number, buffer) != 3 || i < 0 || i > 4) {
			fprintf(stderr, "invalid values\n");
			SKIP
			break;
		}
		SKIP
		if(insert_List(col[i], number, buffer) == 0)
				fprintf(stderr, "insert failed\n");
		break;
	case 'x':
	case 'X':
		printf("Enter list # (between 0 and 4), and the position:\n");
		if(scanf("%d%d", &i, &number) != 2 || i < 0 || i > 4) {
			fprintf(stderr, "invalid values\n");
			SKIP
			break;
		}
		SKIP
		if(delete_List(col[i], number, &pc) == 0)
			fprintf(stderr, "delete failed\n");
		else {
			printf("The deleted string is %s\n", pc);
			free(pc);
		}
	 	break;
	case 'l':
	case 'L': 
		printf("Enter list # (between 0 and 4): \n");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		printf("The length of the list is %d\n", length_List(col[i]));
		break;
	case 'e':
	case 'E':
		printf("Enter enumeration # (between 0 and 4) and the list (to be enumerated) #: \n");
		if(scanf("%d%d", &i, &number) != 2 || i < 0 || i > 4 || number < 0 || number > 4) {
			fprintf(stderr, "invalid values\n");
			SKIP
			break;
		}
		SKIP
		if((enu[i] = construct_Enumeration(col[number])) == NULL)
			fprintf(stderr, "can't initialize\n");
		break;
	case 'm':
	case 'M':
		printf("Enter enumeration # (between 0 and 4): \n");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		printf("There is %s more elements in the enumeration\n",
			hasMoreElements_Enumeration(enu[i]) ? "" : "not");
		break;
	case 'n':
	case 'N': 
		printf("Enter enumeration # (between 0 and 4): \n");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		if((p = nextElement_Enumeration(enu[i])) == NULL) {
			printf("There are no more elements in the enumeration %d\n", i);
			break;
		}
		printf("The next element in the enumeration is %s\n", (char*)p);
		break;
	case 'p':
	case 'P': 
		printf("Enter enumeration # (between 0 and 4): \n");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		printf("Printing using an enumeration %d\n", i);
		while(hasMoreElements_Enumeration(enu[i])) 
			printf("%s\n", nextElementTyped_Enumeration(char*, enu[i]));
		break;
	case 'k':
	case 'K':
		printf("Enter enumeration # (between 0 and 4): \n");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		free(enu[i]);
		enu[i] = NULL;
		break;
	case 'd':
	case 'D':
		printf("Enter list # (between 0 and 4): \n");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		destruct_List(&col[i]);
		col[i] = NULL;
		break;
	case 'q':
	case 'Q': 
		return;
	default :
             fprintf(stderr, "\nUnknown command\n");
             break;
    }

 }
}

int main() {
   menu();
   return EXIT_SUCCESS;
}

