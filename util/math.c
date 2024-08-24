#include "../Unity/src/unity.h"
#include "math.h"

void setUp(void) {
    // Set up
}

void tearDown(void) {
    // Tear down
}

void test_lmin_a_equals_b(void) {
    TEST_ASSERT_EQUAL_INT(5, lmin(5, 5));
}

void test_lmin_a_less_than_b(void) {
    TEST_ASSERT_EQUAL_INT(1, lmin(1, 2));
}

void test_lmin_a_greater_than_b(void) {
    TEST_ASSERT_EQUAL_INT(1, lmin(2, 1));
}

void test_lmax_a_equals_b(void) {
    TEST_ASSERT_EQUAL_INT(5, lmax(5, 5));
}

void test_lmax_a_less_than_b(void) {
    TEST_ASSERT_EQUAL_INT(2, lmax(1, 2));
}

void test_lmax_a_greater_than_b(void) {
    TEST_ASSERT_EQUAL_INT(2, lmax(2, 1));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_lmin_a_equals_b);
    RUN_TEST(test_lmin_a_less_than_b);
    RUN_TEST(test_lmin_a_greater_than_b);

    RUN_TEST(test_lmax_a_equals_b);
    RUN_TEST(test_lmax_a_less_than_b);
    RUN_TEST(test_lmax_a_greater_than_b);

    return UNITY_END();
}
