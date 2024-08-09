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
    size_t s = 0;

    for (s = start; s <= end && s >= 0 && s < input_length && s < output_length; s++) {
        output[s] = input[s];
    }

    if (s < output_length) {
        output[s] = '\0';
    }

    return s;
}
