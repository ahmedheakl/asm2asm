#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int *func0(const char *values, int *size) {
    static int out[256];
    int count = 0;
    const char *start = values;
    char *end;
    while (*start) {
        while (*start && !isdigit(*start) && *start != '-') {
            start++;
        }
        if (!*start) {
            break;
        }
        int val = (int) strtol(start, &end, 10);
        if (start != end && (*end == ',' || *end == '\0')) {
            out[count++] = val;
        } else {
            while (*end && *end != ',') {
                end++;
            }
        }
        start = end;
    }
    *size = count;
    return out;
}
