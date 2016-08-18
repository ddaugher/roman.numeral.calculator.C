#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "GlobalDefines.h"
#include "Converter.h"

static bool input_contains_null(const char* val1, const char* val2) {

	if (val1 == NULL || val2 == NULL) return true;

	return false;

}

void add(char* result, const char* val1, const char* val2){

	if (input_contains_null(val1, val2)) {
		strncpy(result, "ERROR_VAL_NULL", MAX_ROMAN_LENGTH); 
		return;
	}

    convertToRoman(result, convertToArabic(val1) + convertToArabic(val2));
}

void subtract(char* result, const char* val1, const char* val2){

	if (input_contains_null(val1, val2)) {
		strncpy(result, "ERROR_VAL_NULL", MAX_ROMAN_LENGTH); 
		return;
	}

    convertToRoman(result, convertToArabic(val1) - convertToArabic(val2));
}
