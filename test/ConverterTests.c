#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "ConverterTests.h"
#include "../src/Converter.h"

#define MAX_ROMAN_LENGTH	16

START_TEST(test_convert_I_to_1)
        {
                ck_assert_int_eq(1, convertToArabic("I"));
        }

END_TEST

START_TEST(test_convert_V_to_5) {
    ck_assert_int_eq(5, convertToArabic("V"));
}

END_TEST

START_TEST(test_convert_X_to_10) {
    ck_assert_int_eq(10, convertToArabic("X"));
}

END_TEST

START_TEST(test_convert_L_to_50) {
    ck_assert_int_eq(50, convertToArabic("L"));
}

END_TEST

START_TEST(test_convert_C_to_100) {
    ck_assert_int_eq(100, convertToArabic("C"));
}

END_TEST

START_TEST(test_convert_D_to_500) {
    ck_assert_int_eq(500, convertToArabic("D"));
}

END_TEST

START_TEST(test_convert_M_to_1000) {
    ck_assert_int_eq(1000, convertToArabic("M"));
}

END_TEST

START_TEST(test_convert_II_to_2) {
    ck_assert_int_eq(2, convertToArabic("II"));
}

END_TEST

START_TEST(test_convert_III_to_3) {
    ck_assert_int_eq(3, convertToArabic("III"));
}

END_TEST

START_TEST(test_convert_lowercase_v_to_5) {
    ck_assert_int_eq(5, convertToArabic("v"));
}

END_TEST

START_TEST(test_convert_lowercase_x_to_10) {
    ck_assert_int_eq(10, convertToArabic("x"));
}

END_TEST

START_TEST(test_convert_lowercase_l_to_50) {
    ck_assert_int_eq(50, convertToArabic("l"));
}

END_TEST

START_TEST(test_convert_lowercase_c_to_100) {
    ck_assert_int_eq(100, convertToArabic("c"));
}

END_TEST

START_TEST(test_convert_lowercase_d_to_500) {
    ck_assert_int_eq(500, convertToArabic("d"));
}

END_TEST

START_TEST(test_convert_lowercase_m_to_1000) {
    ck_assert_int_eq(1000, convertToArabic("m"));
}

END_TEST

START_TEST(test_convert_IV_to_4) {
    ck_assert_int_eq(4, convertToArabic("IV"));
}

END_TEST

START_TEST(test_convert_IX_to_9) {
    ck_assert_int_eq(9, convertToArabic("IX"));
}

END_TEST

START_TEST(test_convert_XL_to_40) {
    ck_assert_int_eq(40, convertToArabic("XL"));
}

END_TEST

START_TEST(test_convert_LD_to_450) {
    ck_assert_int_eq(450, convertToArabic("LD"));
}

END_TEST

START_TEST(test_convert_VI_to_6) {
    ck_assert_int_eq(6, convertToArabic("VI"));
}

END_TEST

START_TEST(test_convert_CMIII_to_903) {
    ck_assert_int_eq(903, convertToArabic("CMIII"));
}

END_TEST

START_TEST(test_convert_IIX_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("IIX"));
}

END_TEST

START_TEST(test_convert_IXC_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("IXC"));
}

END_TEST

START_TEST(test_convert_IIVVMM_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("IIVVMM"));
}

END_TEST

START_TEST(test_convert_IIII_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("IIII"));
}

END_TEST

START_TEST(test_convert_any_numeral_containing_IIII_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("XIIIIC"));
}

END_TEST

START_TEST(test_convert_XXXX_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("XXXX"));
}

END_TEST

START_TEST(test_convert_any_numeral_containing_XXXX_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("IIXXXXII"));
}

END_TEST

START_TEST(test_convert_CCCC_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("CCCC"));
}

END_TEST

START_TEST(test_convert_any_numeral_containing_CCCC_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("IICCCCII"));
}

END_TEST

START_TEST(test_convert_VV_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("VV"));
}

END_TEST

START_TEST(test_convert_any_numeral_containing_VV_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("IIVVII"));
}

END_TEST

START_TEST(test_convert_LL_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("LL"));
}

END_TEST

START_TEST(test_convert_any_numeral_containing_LL_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("IILLII"));
}

END_TEST

START_TEST(test_convert_DD_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("DD"));
}

END_TEST

START_TEST(test_convert_any_numeral_containing_DD_to_invalid) {
    ck_assert_int_eq(0, convertToArabic("IIDDII"));
}

END_TEST

START_TEST(test_convert_to_proper_arabic_value) {
    ck_assert_int_eq(328, convertToArabic("CCCXXVIII"));
    ck_assert_int_eq(658, convertToArabic("DCLVIII"));
    ck_assert_int_eq(784, convertToArabic("DCCLXXXIV"));
    ck_assert_int_eq(786, convertToArabic("DCCLXXXVI"));
    ck_assert_int_eq(1100, convertToArabic("MC"));
    ck_assert_int_eq(3999, convertToArabic("MMMCMXCIX"));
}

END_TEST

START_TEST(test_convert_1_to_valid_response) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 1);
    ck_assert_int_eq(EXIT_SUCCESS, result);

}

END_TEST

Suite* converterTestsSuite(void) {
    Suite * suite = suite_create("Converter Tests");
    TCase *romanToArabicTestCase = tcase_create("Convert Roman to Arabic");
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
    tcase_add_test(romanToArabicTestCase, test_convert_LD_to_450);
    tcase_add_test(romanToArabicTestCase, test_convert_VI_to_6);
    tcase_add_test(romanToArabicTestCase, test_convert_CMIII_to_903);
    tcase_add_test(romanToArabicTestCase, test_convert_IIX_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_IXC_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_IIVVMM_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_IIII_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_any_numeral_containing_IIII_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_XXXX_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_any_numeral_containing_XXXX_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_CCCC_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_any_numeral_containing_CCCC_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_VV_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_any_numeral_containing_VV_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_LL_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_any_numeral_containing_LL_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_DD_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_any_numeral_containing_DD_to_invalid);
    tcase_add_test(romanToArabicTestCase, test_convert_to_proper_arabic_value);
    TCase *arabicToRomanTestCase = tcase_create("Convert Arabic To Roman");
    tcase_add_test(arabicToRomanTestCase, test_convert_1_to_valid_response);
    suite_add_tcase(suite, romanToArabicTestCase);
    suite_add_tcase(suite, arabicToRomanTestCase);

    return suite;
}
