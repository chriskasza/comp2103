#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ex14-listShallow.h"
#include "ex14-listDeep.h"
#include "ex14-enumShallow.h"
#include "ex14-enumDeep.h"

extern char* strdup(const char*);

/*
 * File: ex14-list-main.c
 * Application of a LIST module 
 *  
 */

/* Callback functions */
void* copyData(const void* v) {
	return strdup((char*)v);
}

void freeData(void* v) {
	free(v);
}

int main() {
	Abstract_List deepList;      /* list containing a deep copy of data */
	Abstract_List shallowList;   /* list containing a shallow copy of data */
	Abstract_Enumeration deepEnum, shallowEnum;
	char *pone = strdup("one");
	char *ptwo = strdup("two");
	char *store[100];
	int i, j;

	/* construct both lists: */
	if((shallowList = construct_Lists(sizeof(char*), NULL, NULL)) == NULL) {
		fprintf(stderr, "construction failed\n");
		return EXIT_FAILURE;
	}
	if((deepList = construct_Lists(sizeof(char*), copyData, freeData)) == NULL) {
		fprintf(stderr, "construction failed\n");
		return EXIT_FAILURE;
	}

	/* Now, insert strings "one" and "two" to both lists: */

	if(insert_ListsDeep(deepList, 0, pone) == 0) {
		fprintf(stderr, "insert failed\n");
		return EXIT_FAILURE;
	}

	if(insert_ListsDeep(deepList, 1, ptwo) == 0) {
		fprintf(stderr, "insert failed\n");
		return EXIT_FAILURE;
	}
	if(insert_ListsShallow(shallowList, 0, pone) == 0) {
		fprintf(stderr, "insert failed\n");
		return EXIT_FAILURE;
	}
	if(insert_ListsShallow(shallowList, 1, ptwo) == 0) {
		fprintf(stderr, "insert failed\n");
		return EXIT_FAILURE;
	}
	/* enumerate shallow list using shallow enumeration */
	if((shallowEnum = construct_Enumeration(shallowList)) == NULL) {
		fprintf(stderr, "enumeration constructor failed\n");
		return EXIT_FAILURE;
	}
	while(hasMoreElements_Enumeration(shallowEnum))
   		printf("%s\n", (char*)nextElement_EnumerationShallow(shallowEnum));
	free(shallowEnum);

	/* enumerate deep list using shallow enumeration */
	if((shallowEnum = construct_Enumeration(deepList)) == NULL) {
		fprintf(stderr, "enumeration constructor failed\n");
		return EXIT_FAILURE;
	}
	while(hasMoreElements_Enumeration(shallowEnum))
   		printf("%s\n", (char*)nextElement_EnumerationShallow(shallowEnum));
	free(shallowEnum);

	/* enumerate deep list using deep enumeration */
	if((deepEnum = construct_Enumeration(deepList)) == NULL) {
		fprintf(stderr, "enumeration constructor failed\n");
		return EXIT_FAILURE;
	}
	for(i = 0; i < 100 && hasMoreElements_Enumeration(deepEnum); i++)
		store[i] = nextElement_EnumerationDeep(deepEnum);
	free(deepEnum);
	
	/* in "store" there are i elements */
	printf("contents of store\n");
	for(j = 0; j < i; j++) {
		printf("%s\n", store[j]);
		free(store[j]);
	}

	return EXIT_SUCCESS;
}

