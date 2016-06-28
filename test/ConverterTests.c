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

START_TEST(test_convert_D_to_500)
   {
    ck_assert_int_eq(500, convertToArabic("D"));
   }
END_TEST

START_TEST(test_convert_M_to_1000)
   {
    ck_assert_int_eq(1000, convertToArabic("M"));
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

START_TEST(test_convert_lowercase_v_to_5)
   {
    ck_assert_int_eq(5, convertToArabic("v"));
   }
END_TEST

START_TEST(test_convert_lowercase_x_to_10)
   {
    ck_assert_int_eq(10, convertToArabic("x"));
   }
END_TEST

START_TEST(test_convert_lowercase_l_to_50)
   {
    ck_assert_int_eq(50, convertToArabic("l"));
   }
END_TEST

START_TEST(test_convert_lowercase_c_to_100)
   {
    ck_assert_int_eq(100, convertToArabic("c"));
   }
END_TEST

START_TEST(test_convert_lowercase_d_to_500)
   {
    ck_assert_int_eq(500, convertToArabic("d"));
   }
END_TEST

START_TEST(test_convert_lowercase_m_to_1000)
   {
    ck_assert_int_eq(1000, convertToArabic("m"));
   }
END_TEST

START_TEST(test_convert_IV_to_4)
   {
    ck_assert_int_eq(4, convertToArabic("IV"));
   }
END_TEST

START_TEST(test_convert_IX_to_9)
   {
    ck_assert_int_eq(9, convertToArabic("IX"));
   }
END_TEST

START_TEST(test_convert_XL_to_40)
   {
    ck_assert_int_eq(40, convertToArabic("XL"));
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
   tcase_add_test(romanToArabicTestCase, test_convert_D_to_500);
   tcase_add_test(romanToArabicTestCase, test_convert_M_to_1000);
   tcase_add_test(romanToArabicTestCase, test_convert_II_to_2);
   tcase_add_test(romanToArabicTestCase, test_convert_III_to_3);
   tcase_add_test(romanToArabicTestCase, test_convert_lowercase_v_to_5);
   tcase_add_test(romanToArabicTestCase, test_convert_lowercase_x_to_10);
   tcase_add_test(romanToArabicTestCase, test_convert_lowercase_l_to_50);
   tcase_add_test(romanToArabicTestCase, test_convert_lowercase_c_to_100);
   tcase_add_test(romanToArabicTestCase, test_convert_lowercase_d_to_500);
   tcase_add_test(romanToArabicTestCase, test_convert_lowercase_m_to_1000);
   tcase_add_test(romanToArabicTestCase, test_convert_IV_to_4);
   tcase_add_test(romanToArabicTestCase, test_convert_IX_to_9);
   tcase_add_test(romanToArabicTestCase, test_convert_XL_to_40);
   suite_add_tcase(suite, romanToArabicTestCase);

   return suite;
}