#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* func0(char** strings, int count) {
    int length = 0;
    for (int i = 0; i < count; i++) {
        length += strlen(strings[i]);
    }
    
    char* out = (char*)malloc(length + 1);
    if (!out) {
        return NULL; 
    }
    
    out[0] = '\0';

    for (int i = 0; i < count; i++) {
        strcat(out, strings[i]);
    }
    
    return out;
}
