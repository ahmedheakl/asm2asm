#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *func0(const char *music_string, int *count) {
    int *out = NULL;
    int size = 0;
    int capacity = 0;

    char current[3] = "";
    int music_string_length = strlen(music_string) + 1;
    char *temp_music_string = malloc(music_string_length + 1);
    strcpy(temp_music_string, music_string);
    strcat(temp_music_string, " ");

    for (int i = 0; i < music_string_length; i++) {
        if (temp_music_string[i] == ' ') {
            if (strcmp(current, "o") == 0) {
                if (size == capacity) {
                    capacity = capacity > 0 ? 2 * capacity : 4;
                    out = realloc(out, capacity * sizeof(int));
                }
                out[size++] = 4;
            }
            if (strcmp(current, "o|") == 0) {
                if (size == capacity) {
                    capacity = capacity > 0 ? 2 * capacity : 4;
                    out = realloc(out, capacity * sizeof(int));
                }
                out[size++] = 2;
            }
            if (strcmp(current, ".|") == 0) {
                if (size == capacity) {
                    capacity = capacity > 0 ? 2 * capacity : 4;
                    out = realloc(out, capacity * sizeof(int));
                }
                out[size++] = 1;
            }
            strcpy(current, "");
        } else {
            size_t len = strlen(current);
            if (len < sizeof(current) - 1) {
                current[len] = temp_music_string[i];
                current[len + 1] = '\0';
            }
        }
    }
    free(temp_music_string);
    *count = size;
    return out;
}
