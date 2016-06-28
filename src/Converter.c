#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "Converter.h"

int romanToInt(const char numberal) {

    if ('M' == toupper(numberal)) {
		return 1000;
	}

    if ('D' == toupper(numberal)) {
		return 500;
	}

    if ('C' == toupper(numberal)) {
		return 100;
	}

    if ('L' == toupper(numberal)) {
		return 50;
	}

    if ('X' == toupper(numberal)) {
		return 10;
	}

    if ('V' == toupper(numberal)) {
		return 5;
	}

	return 1;

}

static bool doesContainIIII(const char* numerals) {
  return strstr(numerals, "IIII") != NULL;
}

static bool doesContainXXXX(const char* numerals) {
  return strstr(numerals, "XXXX") != NULL;
}

static bool doesContainCCCC(const char* numerals) {
  return strstr(numerals, "CCCC") != NULL;
}

static bool containsInvalidVV(const char* numerals) {
  return strstr(numerals, "VV") != NULL;
}

static bool doesContainLL(const char* numerals) {
  return strstr(numerals, "LL") != NULL;
}

static bool doesContainDD(const char* numerals) {
  return strstr(numerals, "DD") != NULL;
}

static bool containsInvalidCombinations(const char* numerals) {
  if(containsInvalidVV(numerals)) return true;

  if(doesContainLL(numerals)) { return true; }

  if(doesContainDD(numerals)) { return true; }

  if(doesContainIIII(numerals)) { return true; }

  if(doesContainXXXX(numerals)) { return true; }

  if(doesContainCCCC(numerals)) { return true; }
}

static bool isValid(const char* numerals) {
	int length = strlen(numerals);

    if (containsInvalidCombinations(numerals)) return false;

	int count = 0;
	int val = 0;
	for(int i = length-1; i>= 0; i--) {
		int current = romanToInt((char)numerals[i]);
		if (val < current) {
			val = current;
		} else if (current < val) {
			count++;
		}

		if (count >= 2) return false;
	}

	return true;
}

const int convertToArabic(const char* numerals) {

	int value = 0;

	if (!isValid(numerals)) {
		return 0;
	}

	if (1 == strlen(numerals)) {
		return romanToInt((char)numerals[0]);
	}

	for(int i = 0; i < strlen(numerals); ++i) {
		int current = romanToInt((char)numerals[i]);

		if (strlen(numerals)-1 == i) {
			value += current;
			break;
		}

		int next = romanToInt((char)numerals[i+1]);

		if (current < next) {
			value -= current;
		} else {
			value += current;
		}
	}

	return value;

}

