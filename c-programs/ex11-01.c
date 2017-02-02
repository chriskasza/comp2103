#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * File: ex11-01.c
 * Operations on a binary file of structures
 * Stores information about students; there are up to 100 students, 
 * for every student we want to store her or his name (up to NAMELENN in size),
 * up to 10 grades, the actual number of grades stored
 * the gpa (grade point average) 
 */
#define STUDENTSN  	100
#define MARKSN  	10
#define NAMELENN  	20
typedef struct {
 	char name[NAMELENN+1];
 	int marksNumber;
 	double marks[MARKSN];
 	double gpa;
} StudentT;

/*
 * Function: saveStudent
 * Purpose: write number structures, contained in the array info, to the file fname. 
 * Inputs: filename, array of students and number of students (parameters)
 * Returns: 1 if successful; otherwise 0
 * Modifies:nothing
 */
 int saveStudent(const char *fname, StudentT info[], int number) {
 	FILE *out;

 	if((out = fopen(fname, "wb")) == NULL)
		return 0;
 	if(fwrite(info, sizeof(StudentT), number, out) != number) {
		fclose(out);
		return 0;
	}
	if(fclose(out) == EOF)
		return 0;
	return 1;
}

/*
 * Function: gpaStudent
 * Purpose: Find the gpa of a student with the given name
 * Returns 0 if it fails, and 1 if it succeeds. In the latter case, it returns
 *   through the third parameter the gpa of the student whose name is studentName. 
 * Inputs: filename, student name (parameters)
 * Returns: 1 if successful; otherwise 0
 * Modifies: the third parameter (gpa)
 */
int gpaStudent(const char *fname, const char *studentName, double *gpa) {
 	FILE *in;
	StudentT buffer;
 
	if((in = fopen(fname, "rb")) == NULL)
		return 0;
 
	while(fread(&buffer, sizeof(StudentT), 1, in) != 0)
 		if(strncmp(buffer.name, studentName, NAMELENN) == 0) {
 			*gpa = buffer.gpa;  /* found */
			if(fclose(in) == EOF)
				return 0;
 			return 1;
 		}
 	/* if here, failed */
	fclose(in);
	return 0;
}

/*
 * Function: updateGpa
 * Purpose: initialize all of the gpa fields; reading data from a file and then
 *	writing them back to this file
 * Inputs: filename (parameter)
 * Returns: 1 if successful; otherwise 0
 * Modifies: the file
 */
int updateGpa(const char *fname) {
	FILE *inOut;
	StudentT buffer;
	int i;
 
	if((inOut = fopen(fname, "r+b")) == NULL)
 		return 0;
 
	/* read one structure at a time */
	while(fread(&buffer, sizeof(StudentT), 1, inOut) != 0) {
 		/* compute gpa */
		for(i = 0, buffer.gpa = 0.0; i < buffer.marksNumber; i++)
			buffer.gpa += buffer.marks[i];
 		/* set gpa */
		if(buffer.marksNumber != 0)
			buffer.gpa /= buffer.marksNumber;
		/* move file pointer to the current structure */
		if(fseek(inOut, -sizeof(StudentT), SEEK_CUR) != 0) {
			fclose(inOut);
			return 0;
		}
 		/* write back */
		if(fwrite(&buffer, sizeof(StudentT), 1, inOut) == 0) {
			fclose(inOut);
			return 0;
		}
	}
 
	if(!feof(inOut)) {
		fclose(inOut);
		return 0;
	}
	if(fclose(inOut) == EOF)
 		return 0;
	return 1;
}

StudentT info[STUDENTSN] = {
	{ "Mary", 1, {100 } },  /* remaining marks and gpa is set to 0 */
	{ "John", 2, {50, 50} }, 
	{ "Boleslaw", 0, {50} },
	{ "Natasha", 10, {100,100} },
	{ "Soon Ping", 10, {100,100, 100,100, 100,100,100,100,100,100} }
};

int main(int argc, char **argv) {
	double gpa;
	char name[NAMELENN+1];
	int count = 5; /*  0<=count<STUDENTSN */
	int i, j;

	if(argc != 2) {
		fprintf(stderr, "usage %s fname\n", argv[0]);
		return EXIT_FAILURE;
	}
	printf("Processing the following data\n\n");
	for(i = 0; i < count; i++) {
		printf("%s\n", info[i].name);
		for(j = 0; j < info[i].marksNumber; j++) {
			printf("mark # %d is %f\t", j, info[i].marks[j]);
			if(j%3 == 0)
				putchar('\n');
		}
		putchar('\n');
	}

	if(saveStudent(argv[1], info, count) == 0) {
		fprintf(stderr, "saveStudent failed\n");
		return EXIT_FAILURE;
	}
	if(updateGpa(argv[1]) == 0) {
		fprintf(stderr, "updateGpa failed\n");
		return EXIT_FAILURE;
	}
	printf("Enter student name:");
	if(fgets(name, NAMELENN, stdin) == NULL) {
		fprintf(stderr, "could not get the name\n");
		return EXIT_FAILURE;
	}
	name[strlen(name)-1] = '\0'; /* overwrite \n */
	if(gpaStudent(argv[1], name, &gpa) == 0) 
		fprintf(stderr, "gpa unknown\n");
	else printf("%s has %f gpa\n", name, gpa);

	return EXIT_SUCCESS;
}

