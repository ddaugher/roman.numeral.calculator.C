#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "ConverterTests.h"
#include "../src/Converter.h"

START_TEST(test_first_failing_test)
   {
    ck_assert_int_eq(1, convertToArabic("I"));
   }
END_TEST

Suite* testSuite(void)
{
   Suite* suite = suite_create("Converter Tests");
   TCase* romanToArabicTestCase = tcase_create("Convert Roman to Arabic");
   tcase_add_test(romanToArabicTestCase, test_first_failing_test);
   suite_add_tcase(suite, romanToArabicTestCase);

   return suite;
}