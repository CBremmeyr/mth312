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

    int temp = 0;
    int codeLen = CODE_END - CODE_START;

    // Check if shift is valid
    if(multInverse(mult, (CODE_END - CODE_START)) <= 0) {
        return -1;
    }

    // Apply shift
    for(int i=0; i<strlen(clear); ++i) {

        temp = ( shift((int)clear[i], mult, offset) % codeLen) + CODE_START;
        cipher[i] = (char)temp;
    }

    return 0;
}
