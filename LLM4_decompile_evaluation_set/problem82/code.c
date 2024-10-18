#include <stdio.h>
#include <stdlib.h>

char** func0(float* grades, int size) {
    char** out = malloc(size * sizeof(char*));
    for (int i = 0; i < size; ++i) {
        if (grades[i] >= 3.9999) out[i] = "A+";
        else if (grades[i] > 3.7001) out[i] = "A";
        else if (grades[i] > 3.3001) out[i] = "A-";
        else if (grades[i] > 3.0001) out[i] = "B+";
        else if (grades[i] > 2.7001) out[i] = "B";
        else if (grades[i] > 2.3001) out[i] = "B-";
        else if (grades[i] > 2.0001) out[i] = "C+";
        else if (grades[i] > 1.7001) out[i] = "C";
        else if (grades[i] > 1.3001) out[i] = "C-";
        else if (grades[i] > 1.0001) out[i] = "D+";
        else if (grades[i] > 0.7001) out[i] = "D";
        else if (grades[i] > 0.0001) out[i] = "D-";
        else out[i] = "E";
    }
    return out;
}
