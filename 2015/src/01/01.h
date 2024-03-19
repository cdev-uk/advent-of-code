#pragma once

#include <string.h>
#include <stdbool.h>

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

int first_position_floor(const char *restrict input, int target_floor) {
    // Positions are 1-indexed
    int current_position = 0;
    int current_floor = 0;
    int input_length = strlen(input);
    bool target_floor_reached = false;

    for (int i = 0; i < input_length && !target_floor_reached; i++) {
        if (current_floor == target_floor) {
            target_floor_reached = true;
        } else {
            current_position++;

            switch (input[i]) {
                case '(':
                    current_floor++;
                    break;
                case ')':
                    current_floor--;
                    break;
            }
        }
    }

    return current_position;
}
