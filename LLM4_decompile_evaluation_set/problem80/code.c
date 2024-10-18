#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* func0(int decimal) {
    char* out = malloc(64);
    if (!out) {
        return NULL;
    }
    int index = 62;
    out[63] = '\0';

    if (decimal == 0) {
        out[index--] = '0';
    } else {
        while (decimal > 0) {
            out[index--] = '0' + (decimal % 2);
            decimal /= 2;
        }
    }

    out[index--] = 'b';
    out[index--] = 'd';

    int start = index + 1;
    int len = 62 - start;
    char* formatted_out = malloc(len + 3);
    if (!formatted_out) {
        free(out);
        return NULL;
    }

    strcpy(formatted_out, &out[start]);

    strcat(formatted_out, "db");

    free(out);

    return formatted_out;
}
