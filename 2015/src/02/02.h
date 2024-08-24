#pragma once

#include <stdlib.h>

#include "../../../util/math.h"
#include "../../../util/strings.h"

#define MAX_LINE_LENGTH 30

long wrapping_paper_length(const char *restrict input) {
    size_t output_length = 20;
    char *output = calloc(output_length, sizeof(char));
    long length = 0;

    explode_sub_string(input, 'x', 0, output, output_length);
    length = strtol(output, NULL, 10);

    free(output);

    return length;
}

long wrapping_paper_width(const char *restrict input) {
    size_t output_length = 20;
    char *output = calloc(output_length, sizeof(char));
    long width = 0;

    explode_sub_string(input, 'x', 1, output, output_length);
    width = strtol(output, NULL, 10);

    free(output);

    return width;
}

long wrapping_paper_height(const char *restrict input) {
    size_t output_length = 20;
    char *output = calloc(output_length, sizeof(char));
    long height = 0;

    explode_sub_string(input, 'x', 2, output, output_length);
    height = strtol(output, NULL, 10);

    free(output);

    return height;
}

long wrapping_paper_square_feet(const char *restrict input) {
    long length = wrapping_paper_length(input);
    long width = wrapping_paper_width(input);
    long height = wrapping_paper_height(input);
    long smallest_side_area = 0;
    long wrapping_paper = 0;

    smallest_side_area = (length * width * height) / lmax(length, lmax(width, height));

    wrapping_paper = 
        (2 * length * width) +
        (2 * width * height) +
        (2 * height * length) +
        smallest_side_area
    ;

    return wrapping_paper;
}

long total_wrapping_paper_square_feet(const char *restrict input, char line_separator) {
    long total_wrapping_paper = 0;

    size_t line_count = char_count(input, line_separator);
    size_t line_index = 0;
    char *current_line = calloc(MAX_LINE_LENGTH, sizeof(char));
    size_t current_line_length = 0;

    for (
        line_index = 0;
        line_index <= line_count;
        line_index++
    ) {
        current_line_length = explode_sub_string(
            input,
            line_separator,
            line_index,
            current_line,
            MAX_LINE_LENGTH
        );

        if (current_line_length > 0) {
            total_wrapping_paper += wrapping_paper_square_feet(current_line);
        }

        memset(current_line, 0, MAX_LINE_LENGTH);
    }

    free(current_line);

    return total_wrapping_paper;
}

long smallest_face_perimeter(const char *restrict input) {
    long length = wrapping_paper_length(input);
    long width = wrapping_paper_width(input);
    long height = wrapping_paper_height(input);

    // There are only three unique perimeters, because each of the 6 faces has
    // a reflection
    long smallest_perimeter = lmin(
        2 * (length + height),
        lmin(
            2 * (height + width),
            2 * (length + width)
        )
    );

    return smallest_perimeter;
}

long cubic_volume(const char *restrict input) {
    long length = wrapping_paper_length(input);
    long width = wrapping_paper_width(input);
    long height = wrapping_paper_height(input);

    return length * width * height;
}

long ribbon_feet(const char *restrict input) {
    return smallest_face_perimeter(input) + cubic_volume(input);
}

long total_ribbon_feet(const char *restrict input, char line_separator) {
    long total_ribbon = 0;

    size_t line_count = char_count(input, line_separator);
    size_t line_index = 0;
    char *current_line = calloc(MAX_LINE_LENGTH, sizeof(char));
    size_t current_line_length = 0;

    for (
        line_index = 0;
        line_index <= line_count;
        line_index++
    ) {
        current_line_length = explode_sub_string(
            input,
            line_separator,
            line_index,
            current_line,
            MAX_LINE_LENGTH
        );

        if (current_line_length > 0) {
            total_ribbon += ribbon_feet(current_line);
        }

        memset(current_line, 0, MAX_LINE_LENGTH);
    }

    free(current_line);

    return total_ribbon;
}
