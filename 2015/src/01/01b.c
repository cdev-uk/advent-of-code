#include <stdlib.h>

#include "../../../util/aoc.h"
#include "../../../util/input.h"

#include "01.h"

#define BASEMENT_FLOOR -1

int main(int argc, char *argv[]) {
    char *input;
    int read_file_result;

    if (argc < 2) {
        return EXIT_FAILURE;
    }

    input = calloc(AOC_INPUT_BUFFER_SIZE, sizeof(char));
    read_file_result = read_file(argv[1], input, AOC_INPUT_BUFFER_SIZE);

    if (read_file_result < 0) {
        return read_file_result;
    }

    printf("%d\n", first_position_floor(input, BASEMENT_FLOOR));

    return EXIT_SUCCESS;
}
