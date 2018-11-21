/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c13e03.c
 *
 * a string compressor; provided a byte value (0-255) and a string, the binary
 * representation of the value will be used as a mask to compress the string.
 * The string will be compressed removing characters that correspond to zero 
 * bits in the mask.
 *
 * example:
 * $ c13e03 97 The quick red fox jumped
 * hec ro jd
 *
 * 01100001_01100001_01100001
 * The quic_k red fo_x jumped
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function:       compress
 * Purpose:        removes ith characters from a given string where the ith 
 *                   bit in a given mask is a zero
 * Inputs:
 *   str:          the string to be compressed
 *   mask:         an 8-bit mask
 * Modifies:       the string provided is modified in memory
 * Error checking: 
 */
void compress(char *str, char mask) {
  char *new;
  char temp[1];
  int i, t;
  int mults = strlen(str)/8;
  unsigned long int fullmask[8];

  if((new = malloc(strlen(str))) == NULL) {
    fprintf(stderr, "unable to allocate memory\n");
    return;
  }

  for(i = 7; i >= 0; i--) {
    t = mask % 2;
    mask >>= 1;
    fullmask[i] = t;
    /*
    for(j = 0; j < 8; j++) {
      fullmask[i] <<= 1;
      fullmask[i] |= t;
    }*/
  }

  if(strlen(str)%8 > 0)
    mults++;

  for(i = 0; i < 8*mults; i++) {
    if(fullmask[i%8] == 1) {
      temp[0] = str[i];
      strcat(new, temp);
    }
    /* 
    for(j = 7; j >= 0; j--) {
      fullmask <<= 8;
      fullmask |= mask;
    } */
  }

  strcpy(str, new);

  return;
}

/*
 * main
 */
int main(int argc, char **argv) {
  char *str;
  char spc[1] = " ";
  int i;
  int stringlen = 0;
  long int mask;

  if(argc < 3) {
    fprintf(stderr, "usage: %s <0-255> <string>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if((mask = strtol(argv[1], &str, 10)) == 0) {
    fprintf(stderr, "usage: %s <1-255> <string>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if(mask < 0 || mask > 255) {
    fprintf(stderr, "usage: %s <0-255> <string>\n", argv[0]);
    return EXIT_FAILURE;
  }

  for(i = 2; i < argc; i++) {
    stringlen += strlen(argv[i]);
    stringlen++;
  }
  stringlen++;

  if((str = malloc(sizeof(char)*stringlen)) == NULL) {
    fprintf(stderr, "unable to allocate memory\n");
    return EXIT_FAILURE;
  }

  for(i = 2; i < argc; i++) {
    strcat(str, argv[i]);
    strcat(str, spc);
  }

  compress(str, (char)mask);

  printf("%s\n", str);
  return EXIT_SUCCESS;
}
