#include <stdio.h>
#include <string.h>
#include <ctype.h>

int func0(const char *str) {
    int count = 0;
    int char_map[256] = {0};
    int index;
    
    for (index = 0; str[index]; index++) {
        char ch = tolower((unsigned char)str[index]);
        if (char_map[ch] == 0 && isalpha((unsigned char)ch)) {
            char_map[ch] = 1;
            count++;
        }
    }
    
    return count;
}
