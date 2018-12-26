/*
 * File:   newcunittestForRoots.c
 * Author: User
 *
 * Created on 25.12.2018, 19:10:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Roots.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testRootsCount() {
    double a;
    double b;
    double c;
    int result = RootsCount(a, b, c);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testFindRoots() {
    double a;
    double b;
    double c;
    Results result = FindRoots(a, b, c);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittestForRoots", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testRootsCount", testRootsCount)) ||
            (NULL == CU_add_test(pSuite, "testFindRoots", testFindRoots))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
