#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "GlobalDefines.h"
#include "Converter.h"

int romanToInt(const char numeral) {

    if ('M' == toupper(numeral)) {
		return ROMAN_M_1000_INT;
	}

    if ('D' == toupper(numeral)) {
		return ROMAN_D_500_INT;
	}

    if ('C' == toupper(numeral)) {
		return ROMAN_C_100_INT;
	}

    if ('L' == toupper(numeral)) {
		return ROMAN_L_50_INT;
	}

    if ('X' == toupper(numeral)) {
		return ROMAN_X_10_INT;
	}

    if ('V' == toupper(numeral)) {
		return ROMAN_V_5_INT;
	}

    if ('I' == toupper(numeral)) {
        return ROMAN_I_1_INT;
    }

	return 0;

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

static bool doesContainVV(const char* numerals) {
  return strstr(numerals, "VV") != NULL;
}

static bool doesContainLL(const char* numerals) {
  return strstr(numerals, "LL") != NULL;
}

static bool doesContainDD(const char* numerals) {
  return strstr(numerals, "DD") != NULL;
}

static bool doesHaveVLeftOfX(const char* numerals) {
  return strstr(numerals, "VX") != NULL;
}

static bool doesHaveLLeftOfC(const char* numerals) {
  return strstr(numerals, "LC") != NULL;
}

static bool doesHaveDLeftOfM(const char* numerals) {
  return strstr(numerals, "DM") != NULL;
}

static bool doesIPreceedInvalidRomanNumeral(const char* numerals) {
  return strstr(numerals, "IL") != NULL || strstr(numerals, "IC") != NULL || strstr(numerals, "ID") != NULL || strstr(numerals, "IM") != NULL;
}

static bool containsInvalidCombinations(const char* numerals) {
  if(doesContainVV(numerals)) return true;

  if(doesContainLL(numerals)) { return true; }

  if(doesContainDD(numerals)) { return true; }

  if(doesContainIIII(numerals)) { return true; }

  if(doesContainXXXX(numerals)) { return true; }

  if(doesContainCCCC(numerals)) { return true; }

  if(doesHaveVLeftOfX(numerals)) { return true; }

  if(doesHaveLLeftOfC(numerals)) { return true; }

  if(doesHaveDLeftOfM(numerals)) { return true; }
  if(doesIPreceedInvalidRomanNumeral(numerals)) { return true; }

  return false;
}

static bool isValid(const char* numerals) {

    if (containsInvalidCombinations(numerals)) return false;

    int length = strlen(numerals);
	int count = 0;
	int val = 0;

    // loop backwards, if more than two values in sequence are
    // smaller than previous, then roman numeral is invalid
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

	int length = strlen(numerals);

	if (1 == length) {
		return romanToInt((char)numerals[0]);
	}

    if (!isValid(numerals)) {
        return 0;
    }


    int total = 0;
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

    if (n < ROMAN_LOWER_LIMIT) return EXIT_FAILURE;
    if (n > ROMAN_UPPER_LIMIT) return EXIT_FAILURE;

    int length = 0;
#define add(ch) if (buf) buf[length] = ch; ++length
    while (n >= ROMAN_M_1000_INT) {
        n -= ROMAN_M_1000_INT;
        add('M');
    };
    if (n >= ROMAN_CM_900_INT) {
        n -= ROMAN_CM_900_INT;
        add('C');
        add('M');
    };
    if (n >= ROMAN_D_500_INT) {
        n -= ROMAN_D_500_INT;
        add('D');
    };
    if (n >= ROMAN_CD_400_INT) {
        n -= ROMAN_CD_400_INT;
        add('C');
        add('D');
    };
    if (n >= ROMAN_C_100_INT) {
        n -= ROMAN_C_100_INT;
        add('C');
    };
    if (n >= ROMAN_XC_90_INT) {
        n -= ROMAN_XC_90_INT;
        add('X');
        add('C');
    };
    if (n >= ROMAN_L_50_INT) {
        n -= ROMAN_L_50_INT;
        add('L');
    };
    if (n >= ROMAN_XL_40_INT) {
        n -= ROMAN_XL_40_INT;
        add('X');
        add('L');
    };
    while (n >= ROMAN_X_10_INT) {
        n -= ROMAN_X_10_INT;
        add('X');
    };
    if (n == ROMAN_IX_9_INT) {
        n -= ROMAN_IX_9_INT;
        add('I');
        add('X');
    };
    if (n >= ROMAN_V_5_INT) {
        n -= ROMAN_V_5_INT;
        add('V');
    };
    if (n == ROMAN_IV_4_INT) {
        n -= ROMAN_IV_4_INT;
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
