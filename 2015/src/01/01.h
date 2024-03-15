#pragma once

#include <string.h>

int final_floor(const char *restrict input) {
    int current_floor = 0;
    int input_length = strlen(input);

    for (int i = 0; i < input_length; i++) {
        switch (input[i]) {
            case '(':
                current_floor++;
                break;
            case ')':
                current_floor--;
                break;
        }
    }
    
    return current_floor;
}
