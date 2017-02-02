#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ex14-listShallow.h"
#include "ex14-listDeep.h"
#include "ex14-enumShallow.h"
#include "ex14-enumDeep.h"

/*
 * File: ex14-list-main1.c
 * Application of a LIST module to double values
 *  
 */

/* Callback functions */
void* copyData(const void* v) {
	return (void*)v;
}

void freeData(void* v) {
}

int main() {
	Abstract_List shallowList;   /* list containing a shallow copy of data */
	Abstract_Enumeration shallowEnum;
	double d1 = 12;
	double d2 = 33;

	if((shallowList = construct_Lists(sizeof(double), NULL, NULL)) == NULL) {
		fprintf(stderr, "construction failed\n");
		return EXIT_FAILURE;
	}
	/* Now, insert 12 and 33: */

	if(insert_ListsShallow(shallowList, 0, &d1) == 0) {
		fprintf(stderr, "insert failed\n");
		return EXIT_FAILURE;
	}

	if(insert_ListsShallow(shallowList, 1, &d2) == 0) {
		fprintf(stderr, "insert failed\n");
		return EXIT_FAILURE;
	}
	/* enumerate shallow list using shallow enumeration */
	if((shallowEnum = construct_Enumeration(shallowList)) == NULL) {
		fprintf(stderr, "enumeration constructor failed\n");
		return EXIT_FAILURE;
	}
	while(hasMoreElements_Enumeration(shallowEnum))
   		printf("%f\n", *((double*)nextElement_EnumerationShallow(shallowEnum)));
	free(shallowEnum);

	return EXIT_SUCCESS;
}

