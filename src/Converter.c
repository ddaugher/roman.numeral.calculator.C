#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Converter.h"

int romanToInt(const char* character) {

	if (strcmp("M", character) == 0) {
		return 1000;
	}

	if (strncasecmp("D", character, 1) == 0) {
		return 500;
	}

	if (strncasecmp("C", character, 1) == 0) {
		return 100;
	}

	if (strncasecmp("L", character, 1) == 0) {
		return 50;
	}

	if (strncasecmp("X", character, 1) == 0) {
		return 10;
	}

	if (strncasecmp("V", character, 1) == 0) {
		return 5;
	}

	return 1;

}

const int convertToArabic(const char* character) {

	int value = 0;

	for(int i = 0; i < strlen(character); ++i) {
		value += romanToInt(character);
	}

	return value;

}

