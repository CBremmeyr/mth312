#include <stdlib.h>
#include "affine-shift.h"

#define VECTOR_LEN (3)

/**
 * Caculate the multiplicative inverse for some number 'mult' mod 
 * another number 'modulo'. The Extended Euclidian Algorithm is used
 * to calculate this.
 * 
 * Return: returns the inverse value if it exists. If there is no 
 *         inverse the a zero is returned. If the inputs are invalid
 *         a negative is returned.
 */
int multInverse(int mult, int modulo) {

    // Inputs must be positive to be valid
    if(mult <= 0 || modulo <= 0) {
        return -1;
    }

    // mod must be larger than mult to be valid
    if(mult >= modulo) {
        return -1;
    }

    int *left = NULL;
    int *right = NULL;
    int *soln = NULL;
	int *temp = NULL;

    int dividend = 0;
    int result = -1;

    // Allocate memory for vectors
    left  = calloc(VECTOR_LEN, sizeof(int));
    right = calloc(VECTOR_LEN, sizeof(int));
    soln  = calloc(VECTOR_LEN, sizeof(int));

    // Check for allocation error
    if(left == NULL || right == NULL || soln == NULL) {
        return -1;
    }

	// Assign top vector values
	left[0] = modulo;
	right[0] = mult;

    // Set initial values
    left[1] = 1;
    left[2] = 0;

    right[1] = 0;
    right[2] = 1;


    // Extended Euclid Algorithem application
    while(1) {

        // Find remainder and dividend
        dividend = left[0] / right[0];
        
        // Calulate sonlution vector
        for(int i = 0; i < VECTOR_LEN; ++i) {
            soln[i] = left[i] - dividend * right[i];
        }

        // Stop at zero, result value is the previous soln[0]
        if(soln[0] == 0) {

			// If mult inverse exists
			if(right[0] == 1) {
				result = mod(right[2], modulo);
			}
			else {
				result = 0;
			}

			break;
		}
    

        // Move vector values by assigning pointer values
		temp  = left;
        left  = right;
        right = soln;
        soln  = temp;
    }

    // Clean up heap
    free(left);
    free(right);
    free(soln);

    return result;
}
