#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "ConverterTests.h"
#include "../src/Converter.h"

START_TEST(test_convert_I_to_1)
   {
    ck_assert_int_eq(1, convertToArabic("I"));
   }
END_TEST

START_TEST(test_convert_II_to_2)
   {
    ck_assert_int_eq(2, convertToArabic("II"));
   }
END_TEST

START_TEST(test_convert_III_to_3)
   {
    ck_assert_int_eq(3, convertToArabic("III"));
   }
END_TEST

Suite* testSuite(void)
{
   Suite* suite = suite_create("Converter Tests");
   TCase* romanToArabicTestCase = tcase_create("Convert Roman to Arabic");
   tcase_add_test(romanToArabicTestCase, test_convert_I_to_1);
   tcase_add_test(romanToArabicTestCase, test_convert_II_to_2);
   tcase_add_test(romanToArabicTestCase, test_convert_III_to_3);
   suite_add_tcase(suite, romanToArabicTestCase);

   return suite;
}