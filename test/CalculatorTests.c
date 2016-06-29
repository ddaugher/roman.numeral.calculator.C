#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "CalculatorTests.h"
#include "../src/Calculator.h"

START_TEST(test_one) {

    ck_assert_int_eq(1, 1);

}
END_TEST

Suite* converterTestsSuite(void) {
    Suite * suite = suite_create("Calculator Tests");
    TCase *addRomanTestCase = tcase_create("add");
    tcase_add_test(addRomanTestCase, test_one);
    suite_add_tcase(suite, addRomanTestCase);

    return suite;
}
