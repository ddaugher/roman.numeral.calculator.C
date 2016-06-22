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

START_TEST(test_convert_V_to_5)
   {
    ck_assert_int_eq(5, convertToArabic("V"));
   }
END_TEST

START_TEST(test_convert_X_to_10)
   {
    ck_assert_int_eq(10, convertToArabic("X"));
   }
END_TEST

START_TEST(test_convert_L_to_50)
   {
    ck_assert_int_eq(50, convertToArabic("L"));
   }
END_TEST

START_TEST(test_convert_C_to_100)
   {
    ck_assert_int_eq(100, convertToArabic("C"));
   }
END_TEST

START_TEST(test_convert_M_to_500)
   {
    ck_assert_int_eq(500, convertToArabic("M"));
   }
END_TEST

Suite* testSuite(void)
{
   Suite* suite = suite_create("Converter Tests");
   TCase* romanToArabicTestCase = tcase_create("Convert Roman to Arabic");
   tcase_add_test(romanToArabicTestCase, test_convert_I_to_1);
   tcase_add_test(romanToArabicTestCase, test_convert_V_to_5);
   tcase_add_test(romanToArabicTestCase, test_convert_X_to_10);
   tcase_add_test(romanToArabicTestCase, test_convert_L_to_50);
   tcase_add_test(romanToArabicTestCase, test_convert_C_to_100);
   tcase_add_test(romanToArabicTestCase, test_convert_M_to_500);
   suite_add_tcase(suite, romanToArabicTestCase);

   return suite;
}