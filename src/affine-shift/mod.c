#include "affine-shift.h"

/**
 * Find the 'val' modulo 'mod' where the result is always positive.
 * 
 * Return: restult of calculation. If error occured returns -1.
 */
int mod(int val, int mod) {

    // Check for valid inputs
    if(mod <= 0) {
        return -1;
    }

	int result = val;

    // Calculate 'val' modulo 'mod'
    if(val < 0) {
        while(result < 0) {
            result += mod;
        }
    }
    else if(val > 0) {
        while(result > mod) {
            result -= mod;
        }

    }
    else {
        return 0;
    }

    return result;
}
