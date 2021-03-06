#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "IntenseTests.h"
#include "../src/GlobalDefines.h"
#include "../src/Converter.h"

START_TEST(test_MDCLXVI_is_valid_for_1666)
    ck_assert_int_eq(1666, convertToArabic("MDCLXVI"));
}

START_TEST(test_V_is_never_written_to_the_left_of_X)
    ck_assert_int_eq(0, convertToArabic("VX"));
    ck_assert_int_eq(0, convertToArabic("VXIII"));
}

START_TEST(test_L_is_never_written_to_the_left_of_C)
    ck_assert_int_eq(0, convertToArabic("LC"));
    ck_assert_int_eq(0, convertToArabic("LCIII"));
}

START_TEST(test_D_is_never_written_to_the_left_of_M)
    ck_assert_int_eq(0, convertToArabic("DM"));
    ck_assert_int_eq(0, convertToArabic("DMIII"));
}

START_TEST(test_I_can_only_preceed_valid_numerals)
    ck_assert_int_eq(4, convertToArabic("IV"));
    ck_assert_int_eq(9, convertToArabic("IX"));
    ck_assert_int_eq(0, convertToArabic("IL"));
    ck_assert_int_eq(0, convertToArabic("IC"));
    ck_assert_int_eq(0, convertToArabic("ID"));
    ck_assert_int_eq(0, convertToArabic("IM"));
}

START_TEST(test_X_can_only_preceed_valid_numerals)
    ck_assert_int_eq(11, convertToArabic("XI"));
    ck_assert_int_eq(15, convertToArabic("XV"));
    ck_assert_int_eq(20, convertToArabic("XX"));
    ck_assert_int_eq(90, convertToArabic("XC"));
    ck_assert_int_eq(0, convertToArabic("XD"));
    ck_assert_int_eq(0, convertToArabic("XD"));
    ck_assert_int_eq(0, convertToArabic("XM"));
}

START_TEST(test_C_can_only_preceed_valid_numerals)
    ck_assert_int_eq(101, convertToArabic("CI"));
    ck_assert_int_eq(105, convertToArabic("CV"));
    ck_assert_int_eq(110, convertToArabic("CX"));
    ck_assert_int_eq(150, convertToArabic("CL"));
    ck_assert_int_eq(200, convertToArabic("CC"));
    ck_assert_int_eq(400, convertToArabic("CD"));
    ck_assert_int_eq(900, convertToArabic("CM"));
}

START_TEST(test_invalid_examples_for_1666)
    ck_assert_int_eq(0, convertToArabic("MDCLXVXI"));
    ck_assert_int_eq(0, convertToArabic("IMDMICLCIXVIIII"));
    ck_assert_int_eq(0, convertToArabic("MDMCLIXVII"));
    ck_assert_int_eq(0, convertToArabic("MDICLCXVII"));
    ck_assert_int_eq(0, convertToArabic("MDMCLIXVXII"));
    ck_assert_int_eq(0, convertToArabic("MDMICLIXVXIII"));
    ck_assert_int_eq(0, convertToArabic("IMDMICLCIXVIV"));
}

Suite* intenseTestsSuite(void) {
    Suite * suite = suite_create("Intense Tests");
    TCase *intenseTestCase = tcase_create("intense");
    tcase_add_test(intenseTestCase, test_MDCLXVI_is_valid_for_1666);
    tcase_add_test(intenseTestCase, test_V_is_never_written_to_the_left_of_X);
    tcase_add_test(intenseTestCase, test_L_is_never_written_to_the_left_of_C);
    tcase_add_test(intenseTestCase, test_D_is_never_written_to_the_left_of_M);
    tcase_add_test(intenseTestCase, test_I_can_only_preceed_valid_numerals);
    tcase_add_test(intenseTestCase, test_C_can_only_preceed_valid_numerals);
    tcase_add_test(intenseTestCase, test_invalid_examples_for_1666);
    suite_add_tcase(suite, intenseTestCase);

    return suite;
}
