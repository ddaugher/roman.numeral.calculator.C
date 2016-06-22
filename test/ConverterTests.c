#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "ConverterTests.h"
#include "../src/Converter.h"

START_TEST(test_first_failing_test)
   {
    ck_assert_str_eq("1", "2");
   }
END_TEST

Suite* testSuite(void)
{
   Suite* suite = suite_create("Roman Calculator Tests");
   TCase* romanToArabicTestCase = tcase_create("Convert Roman to Arabic");
   tcase_add_test(romanToArabicTestCase, test_first_failing_test);
   suite_add_tcase(suite, romanToArabicTestCase);

   return suite;
}