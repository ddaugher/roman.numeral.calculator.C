#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Converter.h"

const int convertToArabic(const char* character) {

	if ("III" == character) {
		return 3;
	}

	if ("V" == character) {
		return 5;
	}

	return 1;
}

