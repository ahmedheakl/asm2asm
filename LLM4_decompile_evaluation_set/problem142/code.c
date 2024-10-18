#include <stdio.h>
#include <string.h>

const char* func0(const char* file_name) {
    int num_digit = 0, num_dot = 0;
    int length = strlen(file_name);
    if (length < 5) return "No";
    char w = file_name[0];
    if (w < 'A' || (w > 'Z' && w < 'a') || w > 'z') return "No";
    const char* last = file_name + length - 4;
    if (strcmp(last, ".txt") != 0 && strcmp(last, ".exe") != 0 && strcmp(last, ".dll") != 0) return "No";
    for (int i = 0; i < length; i++) {
        if (file_name[i] >= '0' && file_name[i] <= '9') num_digit++;
        if (file_name[i] == '.') num_dot++;
    }
    if (num_digit > 3 || num_dot != 1) return "No";
    return "Yes";
}
