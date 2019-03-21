#include <stddef.h>
#include <string.h>

#include "affine-shift.h"

/**
 * Apply an affine shift to string.
 * 
 * Output: 'cipher' is set to the cipher text for the message, if the 
 *         shift is invalid then it is set to NULL.
 * Return: returns zero if no errors, returns -1 if error occured.
 */
int affineShiftE(int mult, int offset, const char *clear, char *cipher) {

    int codeLen = CODE_END - CODE_START;

    // Check if shift is valid
    if(multInverse(mult, codeLen) <= 0) {
        return -1;
    }

    // Apply shift
    for(int i=0; i<strlen(clear); ++i) {
		cipher[i] = (mult * (clear[i] - CODE_START) + offset) % codeLen;	// Apply shift
		cipher[i] += CODE_START;
    }
	cipher[strlen(clear)] = '\0';

    return 0;
}
