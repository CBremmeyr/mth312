#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "affine-shift.h"

#define INPUT_COUNT (4)
#define MULT_INDEX (1)
#define OFFSET_INDEX (2)


/**
 * Encipher message with Affine Shift. Uses multiplier, offset, and message from CLI arguments.
 * To run: $ encipher <multiplier> <offset> <message>
 * 
 * Author: Corbin Bremmeyr
 * Date: 18 March 2019 
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

    // Check for correct number of inputs
    if(argc < INPUT_COUNT) {
        printf("ERROR: too few arguments.\n");
        return 0;
    }

    // Get mult and offset values from CLI arguments
    mult = atoi(argv[MULT_INDEX]);
    offset = atoi(argv[OFFSET_INDEX]);

	// Output mult and offset to uesr for confimation
	printf("Multiplier = %i\nOffset = %i\n", mult, offset);

    // Check if mult value is valid
    if(mult <= 0) {
        printf("ERROR: invalid value for multiplier argument.\n");
        return 0;
    }

    // Find if 'mult' has an inverse
    if(multInverse(mult, codeLen) == 0) {
        printf("WARNING: %i does not have a multiplicative inverse mod %i.\n", mult, codeLen);
    }

    // Allocate memory for clear text and cipher text
    for(int i=3; i<argc; ++i) {
        strLen += strlen(argv[i]);
    }

    clearText  = calloc(strLen, sizeof(char));
    cipherText = calloc(strLen, sizeof(char));

    // Check for allocation errors
    if(clearText == NULL || cipherText == NULL) {
        printf("ERROR: allocation error.\n");
        return 1;
    }

    // Copy clear text from argv
    for(int i=INPUT_COUNT-1; i < argc; ++i) {

        // Make sure that index being checked is valid
        if(i > argc) {
            printf("ERROR: index out of range\n");
        }
        else {
          strcat(clearText, argv[i]);  
        }
    }

	// Print clear text
	printf("Clear Text: %s\n", clearText);

    // Encipher clear text
    affineShiftE(mult, offset, clearText, cipherText);

	// Print cipher text
	printf("Ciper Text: %s\n", cipherText);

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
