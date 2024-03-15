#pragma once

#include <stdio.h>

#define READ_FILE_FAILURE_OPEN -1
#define READ_FILE_FAILURE_READ -2
#define READ_FILE_FAILURE_BUFFER_SIZE -3

int read_file(const char *filename, char *buffer, size_t buffer_size) {
    size_t read_length = 0;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        return READ_FILE_FAILURE_OPEN;
    }

    read_length = fread(buffer, sizeof(char), buffer_size - 1, fp);

    if (read_length < buffer_size) {
        buffer[read_length] = '\0';
    } else {
        return READ_FILE_FAILURE_BUFFER_SIZE;
    }

    if (ferror(fp)) {
        return READ_FILE_FAILURE_READ;
    }

    fclose(fp);

    return 0;
}
