#include <stdio.h>
#include <stdlib.h>

char *func0(int n) {
    int len = 2; 
    for (int i = 1; i <= n; ++i) {
        len += snprintf(NULL, 0, " %d", i);
    }

    char *out = malloc(len);
    if (!out) {
        return NULL;
    }
    
    char *ptr = out;
    ptr += sprintf(ptr, "0");
    for (int i = 1; i <= n; ++i) {
        ptr += sprintf(ptr, " %d", i);
    }
    return out;
}
