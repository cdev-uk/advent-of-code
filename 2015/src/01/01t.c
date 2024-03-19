#include "../../../Unity/src/unity.h"
#include "01.h"

void setUp(void) {
    // Set up
}

void tearDown(void) {
    // Tear down
}

void test_final_floor(void) {
    TEST_ASSERT_EQUAL_INT(0, final_floor("(())"));
    TEST_ASSERT_EQUAL_INT(0, final_floor("()()"));
    TEST_ASSERT_EQUAL_INT(3, final_floor("((("));
    TEST_ASSERT_EQUAL_INT(3, final_floor("(()(()("));
    TEST_ASSERT_EQUAL_INT(3, final_floor("))((((("));
    TEST_ASSERT_EQUAL_INT(-1, final_floor("())"));
    TEST_ASSERT_EQUAL_INT(-1, final_floor("))("));
    TEST_ASSERT_EQUAL_INT(-3, final_floor(")))"));
    TEST_ASSERT_EQUAL_INT(-3, final_floor(")())())"));
}

void test_first_position_floor(void) {
    TEST_ASSERT_EQUAL_INT(1, first_position_floor(")", -1));
    TEST_ASSERT_EQUAL_INT(5, first_position_floor("()())", -1));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_final_floor);
    RUN_TEST(test_first_position_floor);

    return UNITY_END();
}
