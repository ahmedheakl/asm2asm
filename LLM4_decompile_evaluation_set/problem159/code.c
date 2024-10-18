#include <stdio.h>
#include <string.h>

char *func0(char *words[], int count) {
    char *max = "";
    int maxu = 0;
    for (int i = 0; i < count; i++) {
        char unique[256] = {0};
        int unique_count = 0;
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (!strchr(unique, words[i][j])) {
                int len = strlen(unique);
                unique[len] = words[i][j];
                unique[len + 1] = '\0';
                unique_count++;
            }
        }
        if (unique_count > maxu || (unique_count == maxu && strcmp(words[i], max) < 0)) {
            max = words[i];
            maxu = unique_count;
        }
    }
    return max;
}
