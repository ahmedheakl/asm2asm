#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* func0(const char* s) {
    int len = strlen(s);
    char* out = malloc(len + 2); 
    char current[51];
    int out_index = 0, current_index = 0;

    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            for (int j = 0; j < current_index - 1; j++) {
                for (int k = j + 1; k < current_index; k++) {
                    if (current[j] > current[k]) {
                        char temp = current[j];
                        current[j] = current[k];
                        current[k] = temp;
                    }
                }
            }
            if (out_index > 0) out[out_index++] = ' ';
            for (int j = 0; j < current_index; j++) {
                out[out_index++] = current[j];
            }
            current_index = 0;
        } else {
            current[current_index++] = s[i];
        }
    }

    out[out_index] = '\0';
    return out;
}
