/**
 * Affine Shift
 * 
 * Author: Corbin Bremmeyr
 * Date: 11 March 2019
 * Description: Apply affine shift cipher to encrypt command line argument.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INT_DIGITS (10)

// Start and end of visable ASCII characters
#define CODE_START (32)
#define CODE_END (126)

int shift(int val, const int mult, const int offset);
void affineShiftE(const int mult, const int offset, const char *clear, char *cipher);

int main(int argc, char **argv) {

    int strSize = 0;
    char *clearText = NULL;
    char *cipherText = NULL;

    // Get multiplier and offset value from command line parameters
    const int mult = atoi(argv[1]);
    const int offset = atoi(argv[2]);

    // Check if input values may have resulted in integer overflow
    if((argv[1][0] != '-' && mult < 0) || 
       (strlen(argv[1] > MAX_INT_DIGITS))) {
        printf("WARNING: %s may have resulted in integer overflow.", argv[1]);
    }
    if((argv[2][0] != '-' && offset < 0) ||
        (strlen(argv[2] > MAX_INT_DIGITS))) {
        printf("WARNING: %s may have resulted in integer overflow.", argv[2]);
    }

    printf("multiplier = %i, offset = %i\n", mult, offset);

    // TODO: check for valid mult and offset values
    if(mult <= 0) {
        printf("%i parameter should be greater than zero.\n", mult);
        return 0;
    }

    // TODO: Check if affine shift has inverse

    // Calculate total string length of all arguments
    // Start at i=1 to ignore program name argument
    for(int i=3; i<argc; ++i) {
        strSize += sizeof(char) * strlen(argv[i]);
    }

    // Allocate memory for clear and cipher text strings
    clearText = malloc(strSize);
    cipherText = malloc(strSize);

    if(clearText == NULL || cipherText == NULL) {
        printf("ERROR: Malloc returned NULL\n");
        return 1;
    }

    // Concat all argumnet strings into clear text string
    for(int i=3; i < argc; ++i) {

        if(i > (strSize / sizeof(char)) ) {
            printf("ERROR: index out of range\n");
        }
        else {
          strcat(clearText, argv[i]);  
        }
    }

    // Start of cryptographic application //

    // Apply affine shift to clear text
    affineShift(mult, offset, clearText, cipherText);

    printf("Clear text: %s\nCipher text: %s\n", clearText, cipherText);
    // end //

    // Clean up heap
    free(clearText);
    free(cipherText);
    
    return 0;
}


// Apply affine shift to 'clear' and write result to 'cipher'
void affineShiftE(const int mult, const int offset, const char *clear, char *cipher) {

    int temp;

    for(int i=0; i<strlen(clear); ++i) {

        temp = ( shift((int)clear[i], mult, offset) % (CODE_END - CODE_START) ) + CODE_START;
        cipher[i] = (char)temp;
    }
}

// Apply linear shift to single char in clear text
int shift(int val, const int mult, const int offset) {

    return (mult * val + offset);
}

