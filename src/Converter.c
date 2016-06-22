#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Converter.h"

const int convertToArabic(const char* character) {

	if ("III" == character) {
		return 3;
	}
	
	if ("II" == character) {
		return 2;
	}

	return 1;
}

