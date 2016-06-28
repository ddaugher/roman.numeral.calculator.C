#include <stdlib.h>
#include <check.h>
#include "ConverterTests.h"

int main(){
    int numberOfFailedTests;
    Suite* converterSuite = converterTestsSuite();
    SRunner *suiteRunner = srunner_create(converterSuite);
    srunner_run_all(suiteRunner, CK_VERBOSE);
    numberOfFailedTests = srunner_ntests_failed(suiteRunner);
    srunner_free(suiteRunner);

    return (numberOfFailedTests == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
