#include <stdio.h>

#include "affine-shift.h"

int main(void) {

	int codeLen = CODE_END - CODE_START;
	int result = 0;

	printf("Entering Loop.\n\n");

	// Loop over valid inputs for mult inverse
	for(int i=0; i<codeLen; ++i) {

		result = multInverse(i, codeLen);

		// No inverse
		if(result == 0) {

//			printf("i=%i: none\n", i);
		}

		// Invalid input
		else if(result < 0) {

		printf("i=%i: bad input\n", i);	
		}
		else {
			printf("i=%i: %i\n", i, result);
		}
	}

	return 0;
}
