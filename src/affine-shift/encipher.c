#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "affine-shift.h"


/**
 * Bug List:
 *      - Floating point exception
 */


/**
 * Encipher message with Affine Shift. Uses multiplier, offset, and message from CLI arguments.
 * to run: $ encipher <multiplier> <offset> <message>
 * 
 * Author: Corbin Bremmeyr
 * Date: 15 March 2019 
 */
int main(int argc, char **argv) {

    // Make stack variables
    const int codeLen = CODE_END - CODE_START;  // Mod divisor
    int mult = 0;
    int offset = 0;
    FILE *fp = 0;
    int strLen = 0;
    char *clearText = NULL;
    char *cipherText = NULL;

    // Find if 'mult' has an inverse
    if(multInverse(mult, codeLen) == 0) {
        printf("WARNING: %i does not have a multiplicative inverse mod %i.\n", mult, codeLen);
    }

    // Allocate memory for clear text and cipher text
    for(int i=3; i<argc; ++i) {
        strLen += strlen(argv[i]);
    }

    clearText = calloc(sizeof(char), strLen);
    cipherText = calloc(sizeof(char), strLen);

    // Check for allocation errors
    if(clearText == NULL || cipherText == NULL) {
        printf("ERROR: allocation error.\n");
        return 1;
    }

    // Copy clear text from argv
    for(int i=3; i < argc; ++i) {

        // Make sure that index being checked is valid
        if(i > strLen) {
            printf("ERROR: index out of range\n");
        }
        else {
          strcat(clearText, argv[i]);  
        }
    }

    // Encipher clear text
    affineShiftE(mult, codeLen, clearText, cipherText);

    // Open file
    fp = fopen(FILE_NAME, "w");

    // Check if file opened correctly
    if(fp == NULL) {
        printf("ERROR: could not open file.\n");
        // TODO: print errno
        return 1;
    }

    // Write cipher text to file
    fputs(cipherText, fp);

    // Close file
    fclose(fp);

    // Clean up heap
    free(clearText);
    free(cipherText);

    return 0;
}
