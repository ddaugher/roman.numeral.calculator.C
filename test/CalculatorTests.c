#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "CalculatorTests.h"
#include "../src/GlobalDefines.h"
#include "../src/Calculator.h"

START_TEST(test_add_I_and_I_equals_II)
{
    char buf[MAX_ROMAN_LENGTH];
    add(buf, "I", "I");
    ck_assert_str_eq("II", buf);
}
END_TEST

START_TEST(test_add_I_and_IV_equals_V)
{
    char buf[MAX_ROMAN_LENGTH];
    add(buf, "I", "IV");
    ck_assert_str_eq("V", buf);
}
END_TEST

START_TEST(test_add_X_and_C_equals_CX)
{
    char buf[MAX_ROMAN_LENGTH];
    add(buf, "X", "C");
    ck_assert_str_eq("CX", buf);
}
END_TEST

START_TEST(test_subtract_X_and_I_equals_IX)
{
    char buf[MAX_ROMAN_LENGTH];
    subtract(buf, "X", "I");
    ck_assert_str_eq("IX", buf);
}
END_TEST

START_TEST(test_subtract_CCCXC_and_CLXI_equals_IX)
{
    // 390 - 161
    char buf[MAX_ROMAN_LENGTH];
    subtract(buf, "CCCXC", "CLXI");
    ck_assert_str_eq("CXCXXXIX", buf);
}
END_TEST

START_TEST(test_subtract_CLXXI_and_CLXI_equals_IX)
{
    // 171 - 51
    char buf[MAX_ROMAN_LENGTH];
    subtract(buf, "CCCXC", "LI");
    ck_assert_str_eq("CXCLXLXXXXXIX", buf);
}
END_TEST

START_TEST(test_when_first_value_is_null_should_return_error)
{
    char buf[MAX_ROMAN_LENGTH];
    add(buf, NULL, "I");
    ck_assert_str_eq("ERROR_VAL_NULL", buf);
}
END_TEST

Suite* calculatorTestsSuite(void) {
    Suite * suite = suite_create("Calculator Tests");
    TCase *addRomanTestCase = tcase_create("add");
    tcase_add_test(addRomanTestCase, test_add_I_and_I_equals_II);
    tcase_add_test(addRomanTestCase, test_add_I_and_IV_equals_V);
    tcase_add_test(addRomanTestCase, test_add_X_and_C_equals_CX);
    tcase_add_test(addRomanTestCase, test_when_first_value_is_null_should_return_error);
    TCase *subtractRomanTestCase = tcase_create("subtract");
    tcase_add_test(subtractRomanTestCase, test_subtract_X_and_I_equals_IX);
    tcase_add_test(subtractRomanTestCase, test_subtract_CCCXC_and_CLXI_equals_IX);
    tcase_add_test(subtractRomanTestCase, test_subtract_CLXXI_and_CLXI_equals_IX);
    suite_add_tcase(suite, addRomanTestCase);
    suite_add_tcase(suite, subtractRomanTestCase);

    return suite;
}
