#include <stdio.h>
#include <string.h>

void func0(const char* test, int* freq, int* max_count, char* letters) {
    int local_freq[26] = {0}; // for 'a' to 'z'
    int local_max = 0;
    const char* ptr = test;
    int idx = 0;

    while (*ptr) {
        if (*ptr != ' ') {
            int letter_index = *ptr - 'a';
            local_freq[letter_index]++;
            if (local_freq[letter_index] > local_max) {
                local_max = local_freq[letter_index];
            }
        }
        ptr++;
    }

    for (int i = 0; i < 26; i++) {
        freq[i] = local_freq[i];
        if (local_freq[i] == local_max) {
            letters[idx++] = 'a' + i;
        }
    }

    *max_count = local_max;
    letters[idx] = '\0';
}
