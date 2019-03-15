#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "affine-shift.h"

/**
 * Decipher Affine Shift. Takes multiplier and offset values from CLI arguments.
 */
int main(int argc, char **argv) {

    const int codeLen = CODE_END - CODE_START;  // Mod divisor
    int mult = 0;
    int invMult = 0;
    int offset = 0;
    int invOffset = 0;
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

    // Open file with cipher text
    fp = fopen(FILE_NAME, "r");

    // Check for errors opening file
    if(fp == NULL) {
        printf("ERROR: could not open file.\n");
        // TODO: print errno message
        return 1;
    }

    // Read cipher text from file
    fgets(cipherText, sizeof(char) * strLen, fp);

    // Close file
    fclose(fp);

    // Decipher Affine Shift
    affineShiftD(mult, codeLen, clearText, cipherText);

    // Output clear text to user
    printf("Clear text: %s\n", clearText);

    return 0;
}