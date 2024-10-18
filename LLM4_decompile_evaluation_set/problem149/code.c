#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** func0(const char* planet1, const char* planet2, int* returnSize) {
    const char* planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
    int pos1 = -1, pos2 = -1, m;
    for (m = 0; m < 8; m++) {
        if (strcmp(planets[m], planet1) == 0) pos1 = m;
        if (strcmp(planets[m], planet2) == 0) pos2 = m;
    }
    if (pos1 == -1 || pos2 == -1 || pos1 == pos2) {
        *returnSize = 0;
        return NULL;
    }
    if (pos1 > pos2) { int temp = pos1; pos1 = pos2; pos2 = temp; }
    *returnSize = pos2 - pos1 - 1;
    if (*returnSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    char** out = malloc(*returnSize * sizeof(char*));
    for (m = pos1 + 1; m < pos2; m++) {
        out[m - pos1 - 1] = (char*)planets[m];
    }
    return out;
}
