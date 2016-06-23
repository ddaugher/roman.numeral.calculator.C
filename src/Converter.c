#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Converter.h"

const int convertToArabic(const char* character) {

	if (strcmp("M", character) == 0) {
		return 1000;
	}

	if (strcmp("D", character) == 0) {
		return 500;
	}

	if (strcmp("C", character) == 0) {
		return 100;
	}

	if (strcmp("L", character) == 0) {
		return 50;
	}

	if (strcmp("X", character) == 0) {
		return 10;
	}

	if (strcmp("V", character) == 0) {
		return 5;
	}

	return 1;

}

