#include "../Unity/src/unity.h"
#include "strings.h"

#include <stdlib.h>
#include <string.h>

void setUp(void) {
    // Set up
}

void tearDown(void) {
    // Tear down
}

void test_sub_string_empty_string(void) {
    const char *input = "";
    size_t output_length = 5;
    char *output = calloc(output_length, sizeof(char));
    size_t sub_string_length = sub_string(input, 0, 0, output, output_length);

    TEST_ASSERT_EQUAL_size_t(0, sub_string_length);
    TEST_ASSERT_EQUAL_STRING("", output);

    free(output);
}

void test_sub_string_start_end_equal(void) {
    const char *input = "abcde";
    size_t output_length = strlen(input);
    char *output = calloc(output_length, sizeof(char));
    size_t sub_string_length = sub_string(input, 2, 2, output, output_length);

    TEST_ASSERT_EQUAL_size_t(0, sub_string_length);
    TEST_ASSERT_EQUAL_STRING("", output);

    free(output);
}

void test_sub_string_first_character(void) {
    const char *input = "abcde";
    size_t output_length = strlen(input);
    char *output = calloc(output_length, sizeof(char));
    size_t sub_string_length = sub_string(input, 0, 1, output, output_length);

    TEST_ASSERT_EQUAL_size_t(1, sub_string_length);
    TEST_ASSERT_EQUAL_STRING("a", output);

    free(output);
}

void test_sub_string_last_character(void) {
    const char *input = "abcde";
    size_t output_length = strlen(input);
    char *output = calloc(output_length, sizeof(char));
    size_t sub_string_length = sub_string(input, 4, 5, output, output_length);

    TEST_ASSERT_EQUAL_size_t(1, sub_string_length);
    TEST_ASSERT_EQUAL_STRING("e", output);

    free(output);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_sub_string_empty_string);
    RUN_TEST(test_sub_string_start_end_equal);
    RUN_TEST(test_sub_string_first_character);
    RUN_TEST(test_sub_string_last_character);

    return UNITY_END();
}
