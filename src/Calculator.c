#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "Converter.h"

#define MAX_ROMAN_LENGTH	16

void add(char* result, char* val1, char* val2){
    convertToRoman(result, convertToArabic(val1) + convertToArabic(val2));
}
