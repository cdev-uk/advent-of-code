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

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_final_floor);

    return UNITY_END();
}
