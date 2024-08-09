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
    size_t output_index = 0;;

    for (input_index = start, output_index = 0; input_index <= end && input_index >= 0 && input_index < input_length && output_index < output_length; input_index++, output_index++) {
        output[output_index] = input[input_index];
    }

    if (output_index < output_length) {
        output[output_index] = '\0';
    }

    return output_index;
}
