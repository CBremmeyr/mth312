#include <stddef.h>

#include "affine-shift.h"

/**
 * Apply decipher Affine Shift to cipher text using the inverse of 'mult' and 'offset'.
 * 
 * Output: The clear text is placed in 'clearText' string. 'cipherText' and 'clearText' must be the same size.
 * Return: Zero is returned if no errors occured, -1 is returned if an error occured.
 */
int affineShiftD(int mult, int offset, char *clearText, const char *cipherText) {

    const int codeLen = CODE_END - CODE_START;
    int invMult = 0;
    int invOffset = 0;
    int temp = 0;

    // Try to calculate mult's inverse
    invMult = multInverse(mult, codeLen);

    // Check for valid inputs
    // Check if 'mult' has an inverse
    if(invMult == 0) {
        return -1;
    }

    if(offset < 0 || offset >= codeLen) {
        return -1;
    }

    if(clearText == NULL || cipherText == NULL) {
        return -1;
    }

    // Generate inverse shift funciton
    invOffset = mod(offset - codeLen, codeLen);

    // Apply inverse function
    for(int i=0; i < codeLen; ++i) {
        temp = ( shift((int)cipherText[i], invMult, invOffset) % codeLen) + CODE_START;
        clearText[i] = (char)temp;
    }

    // Return zero if no errors
    return 0;
}
