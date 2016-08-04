#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "IntenseTests.h"
#include "../src/GlobalDefines.h"
#include "../src/Converter.h"

START_TEST(test_MDCLXVI_is_valid_for_1666)
    ck_assert_int_eq(1666, convertToArabic("MDCLXVI"));
}


Suite* intenseTestsSuite(void) {
    Suite * suite = suite_create("Intense Tests");
    TCase *intenseTestCase = tcase_create("intense");
    tcase_add_test(intenseTestCase, test_MDCLXVI_is_valid_for_1666);
    suite_add_tcase(suite, intenseTestCase);

    return suite;
}
