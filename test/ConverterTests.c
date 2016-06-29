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

START_TEST(test_convert_0_to_invalid_response) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 0);
    ck_assert_int_eq(EXIT_FAILURE, result);

}

END_TEST

START_TEST(test_convert_1_to_I) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 1);
    ck_assert_str_eq("I", buf);

}
END_TEST

START_TEST(test_convert_2_to_II) {

        char buf[MAX_ROMAN_LENGTH];
        int result = convertToRoman(buf, 2);
        ck_assert_str_eq("II", buf);

}
END_TEST

START_TEST(test_convert_3_to_III) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 3);
    ck_assert_str_eq("III", buf);

}
END_TEST

START_TEST(test_convert_4_to_IV) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 4);
    ck_assert_str_eq("IV", buf);

}
END_TEST

START_TEST(test_convert_5_to_V) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 5);
    ck_assert_str_eq("V", buf);

}
END_TEST

START_TEST(test_convert_6_to_VI) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 6);
    ck_assert_str_eq("VI", buf);

}
END_TEST

START_TEST(test_convert_9_to_IX) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 9);
    ck_assert_str_eq("IX", buf);

}
END_TEST

START_TEST(test_convert_10_to_X) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 10);
    ck_assert_str_eq("X", buf);

}
END_TEST

START_TEST(test_convert_11_to_XI) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 11);
    ck_assert_str_eq("XI", buf);

}
END_TEST

START_TEST(test_convert_20_to_XX) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 20);
    ck_assert_str_eq("XX", buf);

}
END_TEST

START_TEST(test_convert_40_to_XL) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 40);
    ck_assert_str_eq("XL", buf);

}
END_TEST

START_TEST(test_convert_41_to_XLI) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 41);
    ck_assert_str_eq("XLI", buf);

}
END_TEST

START_TEST(test_convert_50_to_L) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 50);
    ck_assert_str_eq("L", buf);

}
END_TEST

START_TEST(test_convert_51_to_LI) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 51);
    ck_assert_str_eq("LI", buf);

}
END_TEST

START_TEST(test_convert_90_to_XC) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 90);
    ck_assert_str_eq("XC", buf);

}
END_TEST

START_TEST(test_convert_91_to_XCI) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 91);
    ck_assert_str_eq("XCI", buf);

}
END_TEST

START_TEST(test_convert_100_to_C) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 100);
    ck_assert_str_eq("C", buf);

}
END_TEST

START_TEST(test_convert_101_to_CI) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 101);
    ck_assert_str_eq("CI", buf);

}
END_TEST

START_TEST(test_convert_400_to_CD) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 400);
    ck_assert_str_eq("CD", buf);

}
END_TEST

START_TEST(test_convert_401_to_CDI) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 401);
    ck_assert_str_eq("CDI", buf);

}
END_TEST

START_TEST(test_convert_500_to_D) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 500);
    ck_assert_str_eq("D", buf);

}
END_TEST

START_TEST(test_convert_501_to_DI) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 501);
    ck_assert_str_eq("DI", buf);

}
END_TEST

START_TEST(test_convert_900_to_CM) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 900);
    ck_assert_str_eq("CM", buf);

}
END_TEST

START_TEST(test_convert_901_to_CMI) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 901);
    ck_assert_str_eq("CMI", buf);

}
END_TEST

START_TEST(test_convert_1000_to_M) {

    char buf[MAX_ROMAN_LENGTH];
    int result = convertToRoman(buf, 1000);
    ck_assert_str_eq("M", buf);

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
    tcase_add_test(arabicToRomanTestCase, test_convert_0_to_invalid_response);
    tcase_add_test(arabicToRomanTestCase, test_convert_1_to_I);
    tcase_add_test(arabicToRomanTestCase, test_convert_2_to_II);
    tcase_add_test(arabicToRomanTestCase, test_convert_3_to_III);
    tcase_add_test(arabicToRomanTestCase, test_convert_4_to_IV);
    tcase_add_test(arabicToRomanTestCase, test_convert_5_to_V);
    tcase_add_test(arabicToRomanTestCase, test_convert_6_to_VI);
    tcase_add_test(arabicToRomanTestCase, test_convert_9_to_IX);
    tcase_add_test(arabicToRomanTestCase, test_convert_10_to_X);
    tcase_add_test(arabicToRomanTestCase, test_convert_11_to_XI);
    tcase_add_test(arabicToRomanTestCase, test_convert_20_to_XX);
    tcase_add_test(arabicToRomanTestCase, test_convert_40_to_XL);
    tcase_add_test(arabicToRomanTestCase, test_convert_41_to_XLI);
    tcase_add_test(arabicToRomanTestCase, test_convert_50_to_L);
    tcase_add_test(arabicToRomanTestCase, test_convert_51_to_LI);
    tcase_add_test(arabicToRomanTestCase, test_convert_90_to_XC);
    tcase_add_test(arabicToRomanTestCase, test_convert_91_to_XCI);
    tcase_add_test(arabicToRomanTestCase, test_convert_100_to_C);
    tcase_add_test(arabicToRomanTestCase, test_convert_100_to_C);
    tcase_add_test(arabicToRomanTestCase, test_convert_101_to_CI);
    tcase_add_test(arabicToRomanTestCase, test_convert_400_to_CD);
    tcase_add_test(arabicToRomanTestCase, test_convert_401_to_CDI);
    tcase_add_test(arabicToRomanTestCase, test_convert_500_to_D);
    tcase_add_test(arabicToRomanTestCase, test_convert_501_to_DI);
    tcase_add_test(arabicToRomanTestCase, test_convert_900_to_CM);
    tcase_add_test(arabicToRomanTestCase, test_convert_901_to_CMI);
    tcase_add_test(arabicToRomanTestCase, test_convert_1000_to_M);
    suite_add_tcase(suite, romanToArabicTestCase);
    suite_add_tcase(suite, arabicToRomanTestCase);

    return suite;
}
