#pragma once

#include <stddef.h>
#include <string.h>

size_t sub_string(
    const char *restrict input,
    size_t start,
    size_t end,
    char *output,
    size_t output_length
) {
    size_t input_length = strlen(input);
    size_t input_index = 0;
    size_t output_index = 0;

    for (
        input_index = start, output_index = 0;
        input_index < end && input_index >= 0 && input_index < input_length && output_index < output_length;
        input_index++, output_index++
    ) {
        output[output_index] = input[input_index];
    }

    if (output_index < output_length) {
        output[output_index] = '\0';
    }

    return output_index;
}

size_t char_count(
    const char *restrict input,
    const char search
) {
    size_t input_length = strlen(input);
    size_t input_index;
    size_t count;

    for (
        input_index = 0, count = 0;
        input_index < input_length;
        input_index++
    ) {
        if (input[input_index] == search) {
            count++;
        }
    }

    return count;
}

int char_position(
    const char *restrict input,
    const char search,
    int search_index
) {
    size_t input_length = strlen(input);
    size_t input_index = 0;
    int count = 0;
    int position = -1;

    for (
        input_index = 0;
        input_index < input_length && position == -1;
        input_index++
    ) {
        if (input[input_index] == search) {
            if (count == search_index) {
                position = input_index;
            } else {
                count++;
            }
        }
    }

    return position;
}

size_t explode_sub_string(
    const char *restrict input,
    const char separator,
    size_t sub_string_index,
    char *output,
    size_t output_length
) {
    size_t input_length = strlen(input);
    size_t separator_count = char_count(input, separator);

    // We begin with the start and end positions set at the start
    // and end of the input, i.e. return the entire string
    size_t start = 0;
    size_t end = input_length;

    // If the index is beyond the separator count, return the empty string
    if (sub_string_index > separator_count) {
        output[0] = '\0';
        return 0;
    }

    // Only search if there is at least one separator and the index is within the range
    if (sub_string_index >= 0 && sub_string_index <= separator_count && separator_count >= 1) {
        if (sub_string_index == 0) {
            end = char_position(
                input,
                separator,
                0
            );
        } else {
            start = char_position(
                input,
                separator,
                sub_string_index - 1
            ) + 1;

            if (sub_string_index < separator_count) {
                end = char_position(
                    input,
                    separator,
                    sub_string_index
                );
            }
        }
    }

    return sub_string(
        input,
        start,
        end,
        output,
        output_length
    );
}
