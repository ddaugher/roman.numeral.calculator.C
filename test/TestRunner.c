#include <stdlib.h>
#include <check.h>
#include "ConverterTests.h"
#include "CalculatorTests.h"
#include "IntenseTests.h"

int main(){
    int numberOfFailedTests;
    Suite* converterSuite = converterTestsSuite();
    Suite* calculatorSuite = calculatorTestsSuite();
    Suite* intenseSuite = intenseTestsSuite();
    SRunner *suiteRunner = srunner_create(converterSuite);
    srunner_add_suite(suiteRunner, calculatorSuite);
    srunner_add_suite(suiteRunner, intenseSuite);
    srunner_run_all(suiteRunner, CK_VERBOSE);
    numberOfFailedTests = srunner_ntests_failed(suiteRunner);
    srunner_free(suiteRunner);

    return (numberOfFailedTests == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
