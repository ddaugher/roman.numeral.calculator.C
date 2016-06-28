#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
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

bool isValid(const char* character) {
	int length = strlen(character);
	if (1 == length) {
		return true;
	}

	if (2 == length) {
		return true;
	}

  if(strstr(character, "IIII") != NULL) {
    return false;
  }

	int count = 0;
	int val = 0;
	for(int i = length-1; i>= 0; i--) {
		int current = romanToInt((char)character[i]);
		if (val < current) {
			val = current;
		} else if (current < val) {
			count++;
		}

		if (count >= 2) return false;
	}

	return true;
}

const int convertToArabic(const char* character) {

	int value = 0;

	if (!isValid(character)) {
		return 0;
	}

	if (1 == strlen(character)) {
		return romanToInt((char)character[0]);
	}

	for(int i = 0; i < strlen(character); ++i) {
		int current = romanToInt((char)character[i]);

		if (strlen(character)-1 == i) {
			value += current;
			break;
		}

		int next = romanToInt((char)character[++i]);


		if (current < next) {
			value += next - current;
		} else {
			value += current + next;
		}
	}

	return value;

}

