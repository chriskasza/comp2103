
Description of all programs from the book "C for Java Programmers"
   

============================================================
=====
Chapter 1:

sample.c
hexadecimal dump

============================================================
=====

Chapter 3:

ex3-1.c
reads two characters and prints them in 
reverse order, separated by a tab and ending with end of line.

ex3-2.c
reads two characters and prints them in 
reverse order, separated by a tab and ending with end of line.
Error checking implemented

ex3-3.c
reads two integers and prints their sum and difference; 
each on a separate line. No error checking.

ex3-4.c
reads two integers and prints their sum and difference; 
each on a separate line. Error checking implemented.

============================================================
=======

Chapter 4:

ex4-1.c
finds the sum of all positive numbers and the sum of negative 
numbers individually, as well as the sum of both. Uses goto.
Test with:
empty.txt: empty
pos-int.txt: only positive numbers
neg-int.txt: only negative numbers
pos-neg-int.txt: positive and negative numbers

ex4-2.c
reads two integer values, and outputs the maximum of these values.
No error checking.

ex4-3.c
outputs the roots of the equation Ax^2+Bx+C = 0.
No check for valid real coefficients. Incorrect version.

ex4-31.c
outputs the roots of the equation Ax^2+Bx+C = 0.
No check for valid real coefficients. Incorrect version.

ex4-32.c
outputs the complex roots of the equation Ax^2+Bx+C = 0. 
Correct version.
Test with:
ex4-32-1.txt: x^2 -2x +1 (one "double" real root)
ex4-32-2.txt: x^2 -3x +2 (two real roots)
ex4-32-3.txt: 3x +2 (one real root)
ex4-32-4.txt: x^2 + 1 (one "double" complex root)
ex4-32-5.txt: 2 (degenerated equation)
ex4-32-6.txt: x^2 -5x + 2 (two complex roots)
wrong-1-int.txt (first integer value is invalid)

ex4-4.c
reads characters until "." and outputs the ASCII value of
the largest input character.
Test with:
empty.txt: 
ex4-4-1.txt: only .
ex4-4-2.txt: ab
ex4-4-3.txt: ab.

ex4-5.c
Reads integers until 0 and output the largest integer
Test with:
empty.txt
zero.txt (only 0)
pos-int.txt (only positive integers)
neg-int.txt (only negative integers)
pos-neg-int.txt (positive and negative integers)
wrong-1-int.txt (first integer value is invalid)
wrong-2-int.txt (second integer value is invalid)

ex4-6.c
Uses the for loop and a comma operator to compute the
sum of integers from 1 to 10

ex4-7.c
Reads two positive integers a and b and outputs the sum and the 
product of odd integers from a (inclusive) to b (exclusive).
Test with:
empty.txt
wrong-1-int.txt (first integer value is invalid)
wrong-2-int.txt (second integer value is invalid)
ex4-7-1.txt (2 3)
ex4-7-2.txt (2 2 -2 -1 3 2 1 3)
ex4-7-3.txt (1 11)

ex4-8.c
Reads two integers a and b and ... 
(find what this program is doing)

ex4-9.c
Reads at most 20 characters and prints the number of blanks,
tabs, asterisks, and lowercase chars

============================================================
========

Chapter 5:

ex5-1.c
Reads three real values from the file TEST1.txt
and displays on the screen the sum of these values

ex5-2.c
Copies a single line from the keyboard and redisplays it. 
No test for eof

ex5-21.c
Copies a single line from the keyboard and redisplays it. 
Tests for eof
Test files:
empty.txt
no-end-line.txt

ex5-3.c
Reads text from the file TEST until end-of-file and outputs to the file 
TEST2 the length of the longest line and the number of this line
Test files:
empty.txt
no-end-line.txt

ex5-4.c
Reads from stdin or the file TEST1, write to stdout or 
the file TEST2
Test files
read from stdio, write to stdout
read from stdio, write to non-existing file TEST2
read from stdio, write to existing file TEST2; 
don't overwrite
read from stdio, write to existing file TEST2; overwrite
read from TEST1, write to stdout
read from non-existing TEST1, write to stdout
read from TEST1, write to stdout

============================================================
==========

Chapter 6:

ex6-1.c
Reads characters until "." and output the ASCII value 
of the largest input character. 
Uses conditional compilation for debugging
Test files:
empty.txt
ex4-4-1.txt: only .
ex4-4-2.txt: ab
ex4-4-3.txt: ab.

============================================================
==========

Chapter 7:

ex7-1.c
Prints a box of N asterisks
----------------------------------------------------------------------
ex7-2.c
Function: digits
Purpose: compute the number of digits in the integer n
ex7-21.c
Function: digits
Purpose: compute the number of digits in the integer n 
(recursive solution)
ex7-2-main.c
Driver for digits from ex7-2.c and from ex7-21.c
ex7-2.make
makefile. Executable: ex7-2
---------------------------------------------------------------------
ex7-3.c
reads characters from the keyboard and return 
the corresponding integer value
---------------------------------------------------------------------
ex7-4-lines.h
A header for the module with two simple operations on lines
ex7-4-lines.c
An implementation for the module with two 
simple operations on lines
ex7-4-lines-main.c
An application of the module with two simple operations on lines
ex7-4-lines.make
makefile. Executable: ex7-4-lines

Test files:
ex7-4-1.txt y=x-1, y=x+1 (parallel)
ex7-4-2.txt y=x-1, y=-x+2 (perpendicular)
ex7-4-3.txt y=3x-1, y=-x+2 
-------------------------------------------------------------------
ex7-5-io.h
A header of the module IO with two simple I/O operations
ex7-5-io.c
An implementation of the module IO
ex7-5-io-main.c
An application of the file module IO
ex7-5-io-main1.c
Another application of the file module IO
ex7-5-io-main2.c
Another application of the file module IO
ex7-5-io.make
makefile. Executables: ex7-51-io ex7-52-io ex7-53-io
------------------------------------------------------------------
ex7-5-io1.h
A header of the module IO1 with two simple I/O operations
ex7-5-io1.c
An implementation of the module IO1
ex7-5-io1-main.c
An application of the file module IO1
ex7-5-io1-main1.c
Another application of the file module IO1
ex7-5-io1-main2.c
Another application of the file module IO1
ex7-5-io1.make
makefile. Executables: ex7-51-io1 ex7-52-io1 ex7-53-io1
-----------------------------------------------------------------
ex7-5-io2.h
A header of the module IO2 with two simple I/O operations
ex7-5-io2.c
An implementation of the module IO2
ex7-5-io2-main.c
An application of the file module IO2
ex7-5-io2-main1.c
Another application of the file module IO2
ex7-5-io2.make
makefile. Executables: ex7-51-io2 ex7-52-io2
-------------------------------------------------------------------
ex7-6-fileOps.h
Header of the module fileOps with various file 
processing operations
ex7-6-fileOps.c
An implementation for the module fileOps
ex7-6-fileOps-main.c
An application of the module fileOps (menu-driven).
ex7-6-fileOps.make
makefile. Executable: ex7-6-fileOps
-------------------------------------------------------------------
ex7-7.c
Illustrates a function with a variable number of arguments.
============================================================
========

Chapter 8:

ex8-1.c
Reads in two integers and then prints
the larger of the two values using an auxiliary pointer.
ex8-2.c
Reads in two integers and then prints the
larger of the two values using two auxiliary pointers.
----------------------------------------------------------------------
ex8-3.c
Function: fileSize
Purpose: Computes the length of a file
ex8-3-main.c
Driver for fileSize from ex8-3.c
ex8-3.make
makefile. Executable: ex8-3

Test files:
empty.txt
source of this file
-----------------------------------------------------------------------
ex8-4.c
Conversions from text to binary and back
------------------------------------------------------------------------
ex8-5.c
Function: show
Purpose: print characters stored in a memory block, 
separated by blanks and enclosed by square brackets.
ex8-52.c
Function: show2
Purpose: print characters stored in a memory block, 
separated by blanks and enclosed by square brackets 
(recursive solution)
ex8-5-main.c
Driver for digits from ex8-5.c and from ex8-52.c
ex8-5.make
makefile. Executable: ex8-5
-----------------------------------------------------------------------
ex8-6.c
Function: get
Purpose: read a single line from the standard input and returns 1
if successful, 0 otherwise.
ex8-6-main.c
driver for get()
ex8-6.make
makefile. Executable: ex8-6
-----------------------------------------------------------------------
ex8-7.c
Demonstrates the dangling reference
-----------------------------------------------------------------------
ex8-8.c
Function: tabulate
Purpose: tabulate function
ex8-8-main.c
driver for tabulate()
ex8-8.make
makefile. Executable: ex8-8
-----------------------------------------------------------------------
ex8-9.c
Function: search
Purpose: search a block of memory of a given size 
for a given double value
ex8-91.c
Function: searchGen
Purpose: search a block of memory of a given size for a given 
value. Generic solution that uses a function compare()
INCORRECT VERSION - see ex8-92.c
ex8-92.c
Function: searchGen
Purpose: search a block of memory of a given size for a given value
Generic solution that uses a function compare()
Includes main to test searchGen()
--------------------------------------------------------------------
ex8-10-ops.h
Header of the generic module Ops with search and sort operations
ex8-10-ops.c
Implementation of the module Ops
ex8-10-ops-main.c
An application of the file module Ops
ex8-10-ops-main1.c
Another application of the file module Ops
ex8-10.make
makefile. Executables: ex8-10-ops ex8-101-ops
The program assumes that there is a binary file "8-10.dat" 
containing double values.
---------------------------------------------------------------------
ex8-11-ops.h
Header of the generic module Ops with search and sort operations
ex8-enum.h
Header of the pure interface for enumerating over data structures
ex8-11-ops.c
Implementation of the module Ops, 
additionally implementation of enumeration
ex8-11-ops-main.c
An application of the file module Ops
ex8-11-ops-main1.c
Another application of the file module Ops
ex8-11.make
makefile. Executables: ex8-111-ops ex8-112-ops
The program assumes that there is a binary file "8-10.dat" 
containing double values
--------------------------------------------------------------------
ex8-11-ops.h
Header of the generic module Ops with search and sort operations
ex8-enum.h
Header of the pure interface for enumerating over data structures
ex8-12-ops.c
Alternative implementation of the module Ops, 
additionally implementation of enumeration
ex8-11-ops-main.c
An application of the file module Ops
ex8-11-ops-main1.c
Another application of the file module Ops
ex8-12-ops.make
makefile. Executables: ex8-111-ops ex8-112-ops
Links with ex8-11.o
The program assumes that there is a binary file "8-10.dat" 
containing double values
---------------------------------------------------------------------
ex8-13-ops1.h
Header of the concrete module Ops1 with search and sort operations
ex8-enum.h
Header of the pure interface for enumerating over data structures
ex8-13-ops1.c
Implementation of the module Ops1 
additionally implementation of enumeration
ex8-13-ops1-main.c
An application of the file module Ops1
ex8-13-ops1-main1.c
Another application of the file module Ops1
ex8-13.make
makefile. Executables: ex8-131-ops1 ex8-132-ops1

============================================================
=====

Chapter 9:

------------------------------------------------------------------
ex9-1.c
Function: modify
Purpose: convert the first character of the input string to 
the upper case
ex9-1-main.c
Driver for modify() from ex9-1.c
ex9-1.make
makefile. Executable: ex9-1
----------------------------------------------------------------
ex9-2.c
Function: modify
Purpose: create a copy of input string with the first argument 
converted to the upper case
ex9-2-main.c
Driver for modify() from ex9-2.c
ex9-2.make
makefile. Executable: ex9-2
-----------------------------------------------------------------
ex9-3.c
Function: modify
Purpose: return through the second parameter
a copy of input string passed as the first parameter
with the first letter converted to the upper case
ex9-3-main.c
Driver for modify() from ex9-3.c
ex9-3.make
makefile. Executable: ex9-3
-----------------------------------------------------------------
ex9-4.c
Function: isNumber
Purpose: check if a string represents an integer value
in decimal or hexadecimal 
ex9-4-main.c
Driver for isNumber() from ex9-4.c
ex9-4.make
makefile. Executable: ex9-4
------------------------------------------------------------------
ex9-5.c
Reads a single word of at most 10 characters
and counts the number of lower case letters
ex9-6.c
Shows output to a string. It reads in an integer
value and outputs a string of characters derived from this 
value
ex9-7.c
Reads two strings representing double value
and outputs the sum of these values
---------------------------------------------------------------------
ex9-8.c
Function: comptext
Purpose: compare two text files fname1 and fname2, line by line
ex9-8-main.c
Driver for comptext() from ex9-8.c
ex9-8.make
makefile. Executable: ex9-8
--------------------------------------------------------------------
ex9-9.c
Function: modify
Purpose: create a copy of input string with the first argument 
converted to the upper case
ex9-2-main.c
Driver for modify() from ex9-9.c
ex9-9.make
makefile. Executable: ex9-9
---------------------------------------------------------------------
ex9-10.c
Reads number of lines from standard input until an
empty line is encountered and then outputs the longest line
---------------------------------------------------------------------
ex9-11.c
Reads in a sequence of strings from a file, stores pointers to 
these strings in a block of memory; sorts the strings using 
Insertion sort, and finally, outputs sorted strings
numberOfLines.c
Computes the number of lines in a file
ex9-11.make:
makefile. Executable: ex9-11
Test files:
empty.txt
zero.txt (single character)
ex9-11-1.txt (single line)
ex9-11-2.txt (two identical lines)
ex9-11-3.txt (two lines; sorted)
ex9-11-4.txt (two lines; not sorted)
---------------------------------------------------------------------
ex9-12.c
Function: pathname
Purpose: retrieve the filename and the directory
ex9-12-main.c
Driver for pathname()
ex9-12.make
makefile. Executable: ex9-12
---------------------------------------------------------------------
ex9-13.c
Function: strip
Purpose: strip leading and trailing characters from a given set
ex9-13-main.c
Driver for strip()
ex9-13.make
makefile. Executable: ex9-13
---------------------------------------------------------------------
ex9-14.c
Function: pathname
Purpose: retrieve the filename and the directory
Implementation using tokens
ex9-12-main.c
Driver for pathname()
ex9-14.make
makefile. Executable: ex9-14
---------------------------------------------------------------------
ex9-token.h
Header of the module Tokens to tokenize a string
ex9-token.c
Implementation of the module Tokens
ex9-15-main.c
Application of the module Tokens
ex9-15.make
makefile. Executable: ex9-15-token

Test files:
ex9-15-1.dat (correct format)
ex9-15-2.dat (incorrect format of the second field)
ex9-15-3.dat (incorrect format of the third field)
ex9-15-4.dat (missing second field)
-------------------------------------------------------------------
ex9-16.c
Displays the number of arguments on the command line
ex9-17.c
Displays up to n lines from a file

============================================================
=======

Chapter 10:

ex10-1.c
A simple version of a calculator program
ex10-2.c
Finds the largest and the smallest value in a double array
-------------------------------------------------------------------
ex10-3.c
Reads from file lines of unlimited length using a single dynamic 
allocation and displays them
Test files:
empty.txt
zero.txt (single character)
ex10-3-1.dat (lines shorter than 10 characters)
ex10-3-2.dat (lines longer than 10 characters)
ex10-4.c
Searches an array of sorted strings looking for a key value
ex10-5.c
Finds the largest value in a two-dimensional array
---------------------------------------------------------------------
ex10-6-Arr.h
Header of the concrete module Arr that implements a 
dynamic array of characters
ex10-6-Arr.c
Implementation of the module Arr
ex10-6-Arr-main.c
Application of the module Arr
Test files:
empty.txt
zero.txt (single character)
ex10-3-1.dat (lines shorter than 10 characters)
ex10-3-2.dat (lines longer than 10 characters)
ex10-6-Arr-main1.c
Another application of the module Arr (menu-driven)
ex10-6-Arr.make
makefile. Executables: ex10-6-Arr ex10-61-Arr
============================================================
=======

Chapter 11:

ex11-01.c
Operations on a binary file of structures
-------------------------------------------------------------------
ex11-enum.h
general enumeration file
ex11-1-Arr.h
Header of the generic module Arr that implements a dynamic array
of characters (with enumerations)
ex11-1-Arr.c
Implementation of the module Arr
ex11-1-Arr-main.c
Application of the module Arr (using char)
Test files:
empty.txt
zero.txt (single character)
ex10-3-1.dat (lines shorter than 10 characters)
ex10-3-2.dat (lines longer than 10 characters)
ex11-1-Arr-main1.c
Another application of the module Arr (using char, menu-driven)
ex11-1-Arr-main2.c
Another application of the module Arr 
(using array of char, menu-driven)
ex11-1-Arr.make
makefile. Executables: ex11-1-Arr ex11-11-Arr ex11-12-Arr 
------------------------------------------------------------------
ex11-enum.h
general enumeration file
ex11-2-list.h
Header of the generic module List that implements concrete lists
of char * (with enumerations)
ex11-2-list.c
Implementation of the module List
ex11-2-list-main.c
Application of the module List
Test files:
empty.txt
zero.txt (single character)
ex10-3-1.dat (lines shorter than 10 characters)
ex10-3-2.dat (lines longer than 10 characters)
ex11-2-list-main1.c
Another application of the module List (menu-driven)
ex11-2-list.make
makefile. Executables: ex11-2-list ex11-21-list
============================================================
=======

Chapter 12:

ex12-1.c
The program reads a text file and stores values in the array of
strings or double values

============================================================
=======

Chapter 13:

ex13-1.c
The program to test functions to get and set bits
============================================================
=======

Chapter 14:

ex14-enum.h
Common interface for shallow and deep enumerations
ex14-enumShallow.h
Enumeration shallow interface
ex14-enumDeep.h
Enumeration deep interface
ex14-list.h
Common interface for shallow and deep lists
ex14-listShallow.h
List shallow interface
ex14-listDeep.h
List deep interface
ex14-list.c
Implementation of the common interface for shallow and deep lists
ex14-listShallow.c
Implementation of the interface for shallow lists
ex14-listDeep.c
Implementation of the interface for deep lists
ex14-list-main.c
Application of the module List
ex14-1-list-main1.c
Another application of the module List (menu-driven)
ex14-1-list.make
makefile. Executables: ex14-list ex141-list 
