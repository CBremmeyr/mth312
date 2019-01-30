#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Change to produce different linear shifts
#define MULT (7)
#define OFFSET (3)

// Start and end of visable ASCII characters
#define CODE_START (32)
#define CODE_END (126)

int shift(int val);
void affineShift(const char *clear, char *cipher);

int main(int argc, char **argv) {

    int strSize = 0;
    char *clearText = NULL;
    char *cipherText = NULL;

    // Calculate total string length of all arguments
    // Start at i=1 to ignore program name argument
    for(int i=1; i<argc; ++i) {
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
    for(int i=1; i < argc; ++i) {

        if(i > (strSize / sizeof(char)) ) {
            printf("ERROR: index out of range\n");
        }
        else {
          strcat(clearText, argv[i]);  
        }
    }

    // Start of cryptographic application //

    // Apply affine shift to clear text
    affineShift(clearText, cipherText);

    printf("Clear text: %s\nCipher text: %s\n", clearText, cipherText);
    // end //

    // Clean up heap
    free(clearText);
    free(cipherText);
    
    return 0;
}


// Apply affine shift to 'clear' and write result to 'cipher'
void affineShift(const char *clear, char *cipher) {

    int temp;

    for(int i=0; i<strlen(clear); ++i) {

        temp = ( shift((int)clear[i]) % (CODE_END - CODE_START) ) + CODE_START;
        cipher[i] = (char)temp;
    }
}

// Apply linear shift to single char in clear text
int shift(int val) {

    return (MULT * val + OFFSET);
}

