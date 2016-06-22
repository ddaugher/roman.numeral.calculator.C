#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Converter.h"

const int convertToArabic(const char* character) {

	if ("II" == character) {
		return 2;
	}
	
	return 1;
}

