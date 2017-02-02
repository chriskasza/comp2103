/*
 * File: x10-13find.c
 * The implementation file for the module find that allows the user to search for words
 *    occurrences in a text file
 *
 * an internal caching system is in place to make searching more efficient
 *
 * Operations: reading of a text file / maintenance of lines from file
 *             showing the contents of the file
 *             searching for words in the stored lines on a per line basis and
 *             globally
*/

#include <stdlib.h>
#include <stdio.h>
#include "ex9-token.h"
#include "x10-11getLine.h"
#include "x10-13find.h"

#define CACHE_SIZE		(4)


/*** PRIVATE VARIABLES ********************/

static FILE *file_ = NULL;
static int initialized_ = 0;
static char * cache_[ CACHE_SIZE  + 1];
static int currentCacheSize_ = 0;

static int lastThingILookedFor_ = CACHE_SIZE / 2; /*stores the last thing we searched for*/


/*** FUNCTION PROTOTYPES ****************/
static void CleanCache();

/*** FUNCTION DEFINITIONS ****************/

/* 
 * LOCAL FUNCTIONS:
*/

/*
 * Purpose: to skip a line of text
*/
static int SkipALine( FILE *f ){

   while( getc( f ) != '\n'){
      if( feof(f))
         return EOF;
   }
   return 1;
}

/*
 * Purpose: helper function that clears the cache
*/
static void CleanCache(){
   int i;

   for( i = 0; i < currentCacheSize_; i++ ){
      free( cache_[i] );
      cache_[i] = NULL;
   }

   lastThingILookedFor_ = -1;
   currentCacheSize_=0;
}
/*
 * Purpose: to determine if word occurs on the line
 * Returns: 1 if so, 0 otherwise
*/
static int findWord( char *word, char *line ){

   /* find the word */
   if( construct_Token( line, "   ") == 0 )
      return 0;
  
   while( hasMore_Token() ){
      if( strcmp( next_Token(), word ) == 0){ /* found it ! */
         destruct_Token();
         return 1;
      }
   }
   /* word not found */
   destruct_Token();
   return 0;
}

/*
 * EXPORTED FUNCTIONS:
*/

/*
 * Function:  construct_Find
 * Purpose:   to construct the module: read the file and store read lines
 * Inputs:    fileName
 * Returns:   1 on success; 0 otherwise
 * Modifies:  internal state of the module
 * Error checking:  checks to ensure file can be opened, required memory
 *             is available
 */
int construct_Find( char *fileName){

	int count, result;
	char *line;

	if( initialized_ )
		return 0;

	if( ( file_ = fopen(fileName , "r")) == NULL )
		return 0; /* error */

	initialized_ = 1;
	
	/* read in the first CACHE_SIZE lines */
	for( count = 0; count < CACHE_SIZE + 1; count++ ){
		result  = getLine( file_, &line );
		if( result == 0 ){
			CleanCache();
			return 0;
		}
		if( result == EOF ) /* nothing left in cache*/
			break;
		/* add the line to the cache */
		cache_ [ currentCacheSize_++] = line;
	}

	lastThingILookedFor_ = CACHE_SIZE/2;
	rewind( file_ ); /* reset the file pointer */

	return 1;
}

/*
 * Function:  destruct_Find
 * Purpose:  to release any memory / reinitialize internal state of module
 * Inputs:  --
 * Returns:  --
 * Modifies:  internal state of module
 * Error checking:  checks to ensure state is initialized
 */
int destruct_Find(){

	int i;

	if( !initialized_)
		return 0;

	if( fclose(file_) == EOF)
		return 0;
	
	initialized_ = 0;
	for( i = 0; i < currentCacheSize_; i++ )
		free( cache_[i] );

	currentCacheSize_ = 0;
	return 1;	
}

/*
 * Function: show_Find
 * Purpose:  shows the i'th line in the file, cache the appropriate lines
 * Inputs:  i, the line number
 * Returns:  1 on success; 0 otherwise
 * Modifies:  the internal cache
 * Error checking:  ensures module is initialized; i is correct
 */
int show_Find( int i){
	int found, count, result;
	char *line;
	int start;

	if (lastThingILookedFor_ == -1) /* error occurred in a previous call */
		return -1;
	
	i--; /* assume user starts counting from 1 : we do it from 0 */
	if( i < 0 ) /* error */
		return -1;

	/* reset the cache */
	CleanCache();

	found = -1;

	start = i-CACHE_SIZE/2 > 0 ? i-CACHE_SIZE/2 : 0;
	for(count = 0; count <= i + CACHE_SIZE/2; count++) {

		if( count < start ){ /* ignore this */
			SkipALine( file_);
			continue;
		}
		result = getLine(file_, &line);

		/* nothing left to read */
		if( result == EOF ){
		        if( i >= count )/* user entered too high a number */{
		        		CleanCache();
         	                rewind(file_);
         	                return -1; /* error */
			}
			found = 0;
			break;
		}

                if( result == 0 ) {  /* something went wrong */
			CleanCache();	
			rewind(file_);
                        return -1; /* error */
		}
		if( count == i ){ /* found it */
			printf("%s\n", line);
			found = 1;
		}

		cache_[ currentCacheSize_++ ]	= line;
	}

	lastThingILookedFor_ = i; 
	rewind(file_);
	return found;
}

/*
 * Function:  search_Find
 * Purpose:  to search for the occurrence of the work globally, and print
 *          the line on which it occurs
 * Inputs:   word, i
 * Returns:  1 if the word is found, 0 otherwise (-1 on error)
 * Modifies: the internal cache
 * Error checking:  ensures module is initialized; i is correct
 */
int search_Find( char *word, int lookOnLine){
	
   char *line;
	int count, result;
	int start, end;

	lookOnLine--; /* assume user starts counting from 1 : we do it from 0 */

	if( lastThingILookedFor_ < 0 || lookOnLine < 0 )
		return -1; /* error */

	/* look in the cache */
	start = lookOnLine - CACHE_SIZE / 2 < 0 ? 0 : lookOnLine - CACHE_SIZE / 2 ;
	end = lookOnLine + CACHE_SIZE / 2 >= currentCacheSize_ ? currentCacheSize_ -1 :
			lookOnLine + CACHE_SIZE / 2 ;

	if( lastThingILookedFor_ >= start && lastThingILookedFor_ <= end ){
		/* it's in the cache */
		int pos;

		/* map the file position to the cache position: it is basically
			the difference between my current search pos and the last
			line number I showed using my show function
		 */
		pos = lastThingILookedFor_ - CACHE_SIZE / 2 > 0 ? 
			lastThingILookedFor_ - CACHE_SIZE / 2 : 0;
		if( findWord( word, cache_[abs(pos - lookOnLine)] ) == 1 )
                       return 1;
		
	}

	/* 
	 * not in the cache and so is either before or after the cache :
         * if it's before, we are ok - we aren't doubly processing lines
         * if it's after, then we skip all the lines up to the lookOnLine
         * position, and again, we are not doubly processing anything
	 * 
	*/

	for(count = 0; count <= lookOnLine; count++) {
           if( count < lookOnLine ){
              SkipALine( file_);
              continue;
           }
	   result = getLine(file_, &line);
	   if( result == EOF){ /* end of file */
		 if( lookOnLine >= count )/* user entered too high a number */{
                    CleanCache();
                    rewind(file_);
                    return -1; /* error */
                 }

		rewind(file_);
		return 0;
	}
        if( result == 0 ) { /* error */
		rewind(file_);
                return -1; 
	}
        /* now find the word */
	if( findWord( word, line ) == 1 ){
		free(line);
		rewind(file_);
		return 1; 
	}
	else { /* did not find the word */
		free(line);
		rewind(file_);
		return 0;
	}
   }
   rewind(file_);
   return 0;
}

/*
 * Function: search_GlobalFind
 * Purpose: to search for the occurrence of the word globally
 * Inputs:  word
 * Returns:  1 if the word may be found, 0 otherwise (-1 on error )
 * Modifies: the internal cache
 * Error checking: ensures module is initialized;
 */
int search_GlobalFind( char *word){
   int result;
   char *line;
	int i, count;
	int start, end;

	if ( lastThingILookedFor_ < 0 )
		return -1; /* error in a previous call */

	/* first look in the cache */
	for(i = 0; i < currentCacheSize_; i++) 
		if( findWord( word, cache_[i] ) == 1 ) 
			return 1;

	/* now try outside of the cache, ignoring what we have already processed */
	start = lastThingILookedFor_ - CACHE_SIZE / 2 ;
        end = lastThingILookedFor_ + CACHE_SIZE / 2;

	 for( count = 0; (result = getLine(file_, &line)) != EOF; count ++){
      if( count >= start && count <= end ){ /* skip stuff in the cache */
         SkipALine( file_);
         continue;
      }
      if( result == EOF ){
	rewind(file_);
        return 0; /* not found */
      }
      else if(result == 0){
	rewind(file_);
        return -1; /* error */
      }

      /* now find the word */
      if( findWord( word, line ) == 1 ){
	free(line);
	rewind(file_);
        return 1; /* found */
     }
     free(line);
   }

   rewind(file_);
   return 0; /* not found */
}


