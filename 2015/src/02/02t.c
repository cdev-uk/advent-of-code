#include "../../../Unity/src/unity.h"
#include "02.h"

void setUp(void) {
    // Set up
}

void tearDown(void) {
    // Tear down
}

void test_wrapping_paper_length(void) {
    TEST_ASSERT_EQUAL_INT(2, wrapping_paper_length("2x3x4"));
}

void test_wrapping_paper_width(void) {
    TEST_ASSERT_EQUAL_INT(3, wrapping_paper_width("2x3x4"));
}

void test_wrapping_paper_height(void) {
    TEST_ASSERT_EQUAL_INT(4, wrapping_paper_height("2x3x4"));
}

void test_wrapping_paper_square_feet(void) {
    TEST_ASSERT_EQUAL_INT(58, wrapping_paper_square_feet("2x3x4"));
    TEST_ASSERT_EQUAL_INT(43, wrapping_paper_square_feet("1x1x10"));
}

void test_total_wrapping_paper_square_feet(void) {
    TEST_ASSERT_EQUAL_INT(101, total_wrapping_paper_square_feet("2x3x4\n1x1x10", '\n'));
    TEST_ASSERT_EQUAL_INT(101, total_wrapping_paper_square_feet("2x3x4\n1x1x10\n", '\n'));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_wrapping_paper_length);
    RUN_TEST(test_wrapping_paper_width);
    RUN_TEST(test_wrapping_paper_height);
    RUN_TEST(test_wrapping_paper_square_feet);
    RUN_TEST(test_total_wrapping_paper_square_feet);

    return UNITY_END();
}
