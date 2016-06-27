#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Converter.h"

int romanToInt(const char character) {

    if ('M' == toupper(character)) {
		return 1000;
	}

    if ('D' == toupper(character)) {
		return 500;
	}

    if ('C' == toupper(character)) {
		return 100;
	}

    if ('L' == toupper(character)) {
		return 50;
	}

    if ('X' == toupper(character)) {
		return 10;
	}

    if ('V' == toupper(character)) {
		return 5;
	}

	return 1;

}

const int convertToArabic(const char* character) {

	int value = 0;

	for(int i = 0; i < strlen(character); ++i) {
		value += romanToInt((char)character[i]);
		printf("Value: %c\n", (char)character[i]);
	}

	return value;

}

