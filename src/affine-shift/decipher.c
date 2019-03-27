#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "affine-shift.h"

#define INPUT_COUNT (3)
#define MULT_INDEX (1)
#define OFFSET_INDEX (2)

/**
 * Decipher Affine Shift. Takes multiplier and offset values from CLI arguments.
 */
int main(int argc, char **argv) {

    const int codeLen = CODE_END - CODE_START;  // Mod divisor
    int mult = 0;
    int offset = 0; 
    FILE *fp = NULL;
    int strLen = 0;
    char *clearText = NULL;
    char *cipherText = NULL;

	// Check for correct number of inputs
	if(argc < INPUT_COUNT) {
		printf("ERROR: too few arguments to be valid.\n");
		return 0;
	}
	
	// Get multiplier value from CLI arguments
	mult = atoi(argv[MULT_INDEX]);
	offset = atoi(argv[OFFSET_INDEX]);

	// Output mult and offset values to user for confimation
	printf("Multiplier = %i\nOffset = %i\n", mult, offset);

	// Check for valid mult value
	if(mult < 0) {
		printf("ERROR: invalid value for multiplier arg.\n");
	}

    // Find if 'mult' has an inverse
    if(multInverse(mult, codeLen) == 0) {
        printf("WARNING: %i does not have a multiplicative inverse mod %i.\n", mult, codeLen);
    }

    // Open file with cipher text
    fp = fopen(FILE_NAME, "r");

    // Check for errors opening file
    if(fp == NULL) {
        printf("ERROR: could not open file.\n");
        // TODO: print errno message
        return 1;
    }

	// Get length of cipher text
	fseek(fp, 0, SEEK_END);
	strLen = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	// Allocate memory for cipher and clear text strings	
    clearText  = (char *) calloc(strLen + 1, sizeof(char));
    cipherText = (char *) calloc(strLen + 1, sizeof(char));
	
    // Check for allocation errors
    if(clearText == NULL || cipherText == NULL) {
        printf("ERROR: allocation error.\n");
        return 1;
    }

    // Read cipher text from file
    if(fgets(cipherText, strLen + 1, fp) == NULL) {
		printf("No cipher text read.\n");
		return 1;
	}

	// Close file
    fclose(fp);

	// Print cipher text
	printf("Cipher text: %s\n", cipherText);

    // Decipher Affine Shift
    affineShiftD(mult, offset, clearText, cipherText);

    // Output clear text to user
    printf("Clear text: %s\n", clearText);

    return 0;
}

