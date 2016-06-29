#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "CalculatorTests.h"
#include "../src/Calculator.h"

START_TEST(test_add_I_and_I_equals_II)
{
    char buf[16];
    add(buf, "I", "I");
    ck_assert_str_eq("II", buf);
}
END_TEST

START_TEST(test_add_I_and_IV_equals_II)
{
    char buf[16];
    add(buf, "I", "IV");
    ck_assert_str_eq("V", buf);
}
END_TEST

START_TEST(test_add_X_and_C_equals_CX)
{
    char buf[16];
    add(buf, "X", "C");
    ck_assert_str_eq("CX", buf);
}
END_TEST

Suite* calculatorTestsSuite(void) {
    Suite * suite = suite_create("Calculator Tests");
    TCase *addRomanTestCase = tcase_create("add");
    tcase_add_test(addRomanTestCase, test_add_I_and_I_equals_II);
    tcase_add_test(addRomanTestCase, test_add_I_and_IV_equals_II);
    tcase_add_test(addRomanTestCase, test_add_X_and_C_equals_CX);
    suite_add_tcase(suite, addRomanTestCase);

    return suite;
}
