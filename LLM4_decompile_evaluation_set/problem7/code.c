#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* func0(const char* paren_string, int* returnSize) {
    int* all_levels = NULL;
    int level = 0, max_level = 0, i = 0, count = 0;
    char chr;
    for (i = 0; paren_string[i] != '\0'; i++) {
        chr = paren_string[i];
        if (chr == '(') {
            level += 1;
            if (level > max_level) max_level = level;
        } else if (chr == ')') {
            level -= 1;
            if (level == 0) {
                all_levels = (int*)realloc(all_levels, sizeof(int) * (count + 1));
                all_levels[count++] = max_level;
                max_level = 0;
            }
        }
    }
    *returnSize = count;
    return all_levels;
}
