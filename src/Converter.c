#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Converter.h"

const int convertToArabic(const char* character) {

	if ("X" == character) {
		return 10;
	}

	if ("V" == character) {
		return 5;
	}

	return 1;
}

