#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>


/*Returns a substring containing only the filename from a given path.
  For example given the path C:\Books\HappyPuppy.pdf the returned
  substring is HappyPuppy.pdf
*/
char * getFilenameFromPath(const char * path);


/* Returns an integer containing the number of words in the given file.
   Words must be separated with a new line character to be counted.
*/
int numberOfWordsInFile(FILE * file);





#endif

