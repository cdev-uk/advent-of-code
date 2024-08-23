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

void test_char_count(void) {
    TEST_ASSERT_EQUAL_size_t(0, char_count("abcde", 'f'));
    TEST_ASSERT_EQUAL_size_t(1, char_count("abcde", 'a'));
    TEST_ASSERT_EQUAL_size_t(1, char_count("abcde", 'c'));
    TEST_ASSERT_EQUAL_size_t(1, char_count("abcde", 'e'));
    TEST_ASSERT_EQUAL_size_t(5, char_count("xxxxx", 'x'));
    TEST_ASSERT_EQUAL_size_t(3, char_count("axxxa", 'x'));
    TEST_ASSERT_EQUAL_size_t(3, char_count("xaxax", 'x'));
    TEST_ASSERT_EQUAL_size_t(2, char_count("axaxa", 'x'));
}

void test_char_position(void) {
    TEST_ASSERT_EQUAL_INT(-1, char_position("abcde", 'f', 0));
    TEST_ASSERT_EQUAL_INT(-1, char_position("abcde", 'f', 4));
    TEST_ASSERT_EQUAL_INT(0, char_position("abcde", 'a', 0));
    TEST_ASSERT_EQUAL_INT(0, char_position("axxxa", 'a', 0));
    TEST_ASSERT_EQUAL_INT(4, char_position("axxxa", 'a', 1));
    TEST_ASSERT_EQUAL_INT(0, char_position("xaxax", 'x', 0));
    TEST_ASSERT_EQUAL_INT(2, char_position("xaxax", 'x', 1));
    TEST_ASSERT_EQUAL_INT(1, char_position("1x2x3", 'x', 0));
}

void test_explode_sub_string_first(void) {
    size_t output_length = 20;
    char *output = calloc(output_length, sizeof(char));
    explode_sub_string("1x2x3", 'x', 0, output, output_length);

    TEST_ASSERT_EQUAL_STRING("1", output);

    free(output);
}

void test_explode_sub_string_middle(void) {
    size_t output_length = 20;
    char *output = calloc(output_length, sizeof(char));
    explode_sub_string("1x2x3", 'x', 1, output, output_length);

    TEST_ASSERT_EQUAL_STRING("2", output);

    free(output);
}

void test_explode_sub_string_last(void) {
    size_t output_length = 20;
    char *output = calloc(output_length, sizeof(char));
    explode_sub_string("1x2x3", 'x', 2, output, output_length);

    TEST_ASSERT_EQUAL_STRING("3", output);

    free(output);
}

void test_explode_sub_string_no_separator_match(void) {
    size_t output_length = 20;
    char *output = calloc(output_length, sizeof(char));
    explode_sub_string("1x2x3", 'y', 0, output, output_length);

    TEST_ASSERT_EQUAL_STRING("1x2x3", output);

    free(output);
}

void test_explode_sub_string_index_too_high(void) {
    size_t output_length = 20;
    char *output = calloc(output_length, sizeof(char));
    explode_sub_string("1x2x3", 'y', 3, output, output_length);

    TEST_ASSERT_EQUAL_STRING("", output);

    free(output);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_sub_string_empty_string);
    RUN_TEST(test_sub_string_start_end_equal);
    RUN_TEST(test_sub_string_first_character);
    RUN_TEST(test_sub_string_last_character);

    RUN_TEST(test_char_count);

    RUN_TEST(test_char_position);

    RUN_TEST(test_explode_sub_string_first);
    RUN_TEST(test_explode_sub_string_middle);
    RUN_TEST(test_explode_sub_string_last);
    RUN_TEST(test_explode_sub_string_no_separator_match);
    RUN_TEST(test_explode_sub_string_index_too_high);

    return UNITY_END();
}
