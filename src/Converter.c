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

  return false;
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
			count = 0;
		} else if (current < val) {
			count++;
		}

		if (count >= 2) return false;
	}

	return true;
}

const int convertToArabic(const char* numerals) {

	int total = 0;

	if (!isValid(numerals)) {
		return 0;
	}

	int length = strlen(numerals);

	if (1 == length) {
		return romanToInt((char)numerals[0]);
	}

	for(int i = 0; i < length; ++i) {
		int current = romanToInt((char)numerals[i]);

		if (length-1 == i) {
			total += current;
			break;
		}

		int next = romanToInt((char)numerals[i+1]);

		if (current < next) {
			total -= current;
		} else {
			total += current;
		}
	}

	return total;

}

const int convertToRoman(char* buf, int n) {

    int length = 0;
    if (n <= 0) return EXIT_FAILURE;

#define add(ch) if (buf) buf[length] = ch; ++length
    if (n == 400) {
        n -= 400;
        add('C');
        add('D');
    };
    if (n >= 100) {
        n -= 100;
        add('C');
    };
    if (n >= 90) {
        n -= 90;
        add('X');
        add('C');
    };
    if (n >= 50) {
        n -= 50;
        add('L');
    };
    if (n >= 40) {
        n -= 40;
        add('X');
        add('L');
    };
    while (n >= 10) {
        n -= 10;
        add('X');
    };
    if (n == 9) {
        n -= 9;
        add('I');
        add('X');
    };
    if (n >= 5) {
        n -= 5;
        add('V');
    };
    if (n == 4) {
        n -= 4;
        add('I');
        add('V');
    };
    while (n) {
        --n;
        add('I');
    };
    add('\0');
#undef add

    return EXIT_SUCCESS;
}
