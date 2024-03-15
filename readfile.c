#include <stdlib.h>

#include "util/input.h"

#define BUFFER_SIZE 51200

int main(int argc, char *argv[]) {
    char *buffer;
    int read_file_result;

    if (argc > 1) {
        buffer = calloc(BUFFER_SIZE, sizeof(char));
        read_file_result = read_file(argv[1], buffer, BUFFER_SIZE);

        if (read_file_result >= 0) {
            printf("%s\n", buffer);
            return EXIT_SUCCESS;
        } else {
            return read_file_result;
        }
    } else {
        printf("No filename specified\n");
        return EXIT_FAILURE;
    }
}
