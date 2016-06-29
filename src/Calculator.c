#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "GlobalDefines.h"
#include "Converter.h"

void add(char* result, char* val1, char* val2){
    convertToRoman(result, convertToArabic(val1) + convertToArabic(val2));
}

void delete(char* result, char* val1, char* val2){
    convertToRoman(result, convertToArabic(val1) - convertToArabic(val2));
}
