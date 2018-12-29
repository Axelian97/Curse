#include <config.h>
#include <stdlib.h>
#include <stdint.h>
#include <check.h>
#include "../src/roots.h"

void setup(void)
{
    
}

void teardown(void)
{

}

START_TEST(find_two_roots)
{
	double a = 2;
    double b = 3;
    double c = -2;
    Results result = FindRoots(a,b,c);
    Results expected;
    expected.x1 = 0.5;
    expected.x2 = -2;
    expected.ExistenceRealRoots = 1;
    ck_assert(result.x1==expected.x1);
    ck_assert(result.x2==expected.x2);
    ck_assert_int_eq(result.ExistenceRealRoots,expected.ExistenceRealRoots);
}
END_TEST

START_TEST(find_one_root)
{
    double a = 2;
    double b = 4;
    double c = 2;
    Results result = FindRoots(a,b,c);
    Results expected;
    expected.x1 = -1;
    expected.x2 = -1;
    expected.ExistenceRealRoots = 1;
    ck_assert(result.x1==expected.x1);
    ck_assert(result.x2==expected.x2);
    ck_assert_int_eq(result.ExistenceRealRoots,expected.ExistenceRealRoots);
}
END_TEST

START_TEST(find_zero_roots)
{
    double a = 3;
    double b = 3;
    double c = 3;
    Results result = FindRoots(a,b,c);
    Results expected;
    expected.x1 = 0;
    expected.x2 = 0;
    expected.ExistenceRealRoots = 0;
    ck_assert(result.x1==expected.x1);
    ck_assert(result.x2==expected.x2);
    ck_assert_int_eq(result.ExistenceRealRoots,expected.ExistenceRealRoots);
}
END_TEST

START_TEST(test_factorial)
{
    int arg = 3;
    long result = factorial(arg);
    ck_assert_int_eq(result,6);
}
END_TEST

START_TEST(root_count_2root)
{
    double a = 3;
    double b = 3;
    double c = -3;
    int result = RootsCount(a,b,c);
    ck_assert_int_eq(result,2);
}
END_TEST

START_TEST(root_count_1root)
{
    double a = 2;
    double b = 4;
    double c = 2;
    int result = RootsCount(a,b,c);
    ck_assert_int_eq(result,1);
}
END_TEST

START_TEST(root_count_0root)
{
    double a = 3;
    double b = 3;
    double c = 3;
    int result = RootsCount(a,b,c);
    ck_assert_int_eq(result,0);
}
END_TEST

Suite * roots_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roots");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, find_two_roots);
    tcase_add_test(tc_core, find_one_root);
    tcase_add_test(tc_core, find_zero_roots);
    tcase_add_test(tc_core, test_factorial);
    tcase_add_test(tc_core, root_count_2root);
    tcase_add_test(tc_core, root_count_1root);
    tcase_add_test(tc_core, root_count_0root);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roots_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
