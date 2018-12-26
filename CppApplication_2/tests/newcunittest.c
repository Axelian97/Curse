/*
 * File:   newcunittest.c
 * Author: User
 *
 * Created on 25.12.2018, 15:34:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Roots.h"
#include <check.h>

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

Results FindRoots(double a, double b, double c);

void testFindRoots_2root(){
    double a = 2;
    double b = 3;
    double c = -2;
    Results result = FindRoots(a,b,c);
    Results expected;
    expected.x1 = 0.5;
    expected.x2 = -2;
    expected.ExistenceRealRoots = 1;
    CU_ASSERT_EQUAL(result.x1,expected.x1);
    CU_ASSERT_EQUAL(result.x2,expected.x2);
    CU_ASSERT_EQUAL(result.ExistenceRealRoots,expected.ExistenceRealRoots);
}

void testFindRoots_1root(){
    double a = 2;
    double b = 4;
    double c = 2;
    Results result = FindRoots(a,b,c);
    Results expected;
    expected.x1 = -1;
    expected.x2 = -1;
    expected.ExistenceRealRoots = 1;
    CU_ASSERT_EQUAL(result.x1,-1);
    CU_ASSERT_EQUAL(result.x2,expected.x2);
    CU_ASSERT_EQUAL(result.ExistenceRealRoots,expected.ExistenceRealRoots);
}

void testFindRoots_0root(){
    double a = 3;
    double b = 3;
    double c = 3;
    Results result = FindRoots(a,b,c);
    Results expected;
    expected.x1 = 0;
    expected.x2 = 0;
    expected.ExistenceRealRoots = 0;
    CU_ASSERT_EQUAL(result.x1,expected.x1);
    CU_ASSERT_EQUAL(result.x2,expected.x2);
    CU_ASSERT_EQUAL(result.ExistenceRealRoots,expected.ExistenceRealRoots);
}

long factorial(int arg);

void testFactorial() {
    int arg = 3;
    long result = factorial(arg);
    CU_ASSERT_EQUAL(result,6);
}

int RootsCount(double a, double b, double c);

void testRootCount_2root() {
    double a = 3;
    double b = 3;
    double c = -3;
    int result = RootsCount(a,b,c);
    CU_ASSERT_EQUAL(result,2);
}

void testRootCount_1root() {
    double a = 2;
    double b = 4;
    double c = 2;
    int result = RootsCount(a,b,c);
    CU_ASSERT_EQUAL(result,1);
}

void testRootCount_0root() {
    double a = 3;
    double b = 3;
    double c = 3;
    int result = RootsCount(a,b,c);
    CU_ASSERT_EQUAL(result,0);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testFactorial", testFactorial)) ||
            (NULL == CU_add_test(pSuite, "testRootCount_2root", testRootCount_2root)) ||
            (NULL == CU_add_test(pSuite, "testRootCount_1root", testRootCount_1root)) ||
            (NULL == CU_add_test(pSuite, "testRootCount_0root", testRootCount_0root)) ||
            (NULL == CU_add_test(pSuite, "testFindRoots_2root", testFindRoots_2root)) ||
            (NULL == CU_add_test(pSuite, "testFindRoots_1root", testFindRoots_1root)) ||
            (NULL == CU_add_test(pSuite, "testFindRoots_0root", testFindRoots_0root))
            ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
