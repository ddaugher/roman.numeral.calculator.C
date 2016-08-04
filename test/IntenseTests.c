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
}

Suite* intenseTestsSuite(void) {
    Suite * suite = suite_create("Intense Tests");
    TCase *intenseTestCase = tcase_create("intense");
    tcase_add_test(intenseTestCase, test_MDCLXVI_is_valid_for_1666);
    tcase_add_test(intenseTestCase, test_V_is_never_written_to_the_left_of_X);
    tcase_add_test(intenseTestCase, test_L_is_never_written_to_the_left_of_C);
    tcase_add_test(intenseTestCase, test_D_is_never_written_to_the_left_of_M);
    tcase_add_test(intenseTestCase, test_I_can_only_preceed_valid_numerals);
    suite_add_tcase(suite, intenseTestCase);

    return suite;
}
