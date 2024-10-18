#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void func0(const char* sentence, char* out) {
    int index = 0, word_len = 0;
    int out_index = 0;
    bool is_prime;
    int i, j;

    for (i = 0; sentence[i] != '\0'; ++i) {
        if (sentence[i] != ' ') {
            word_len++;
        } else {
            if (word_len > 1) {
                is_prime = true;
                for (j = 2; j * j <= word_len; ++j) {
                    if (word_len % j == 0) {
                        is_prime = false;
                        break;
                    }
                }
            } else {
                is_prime = false;
            }

            if (is_prime) {
                if (out_index > 0) {
                    out[out_index++] = ' ';
                }
                memcpy(out + out_index, sentence + i - word_len, word_len);
                out_index += word_len;
            }
            word_len = 0;
        }
    }

    if (word_len > 1) {
        is_prime = true;
        for (j = 2; j * j <= word_len; ++j) {
            if (word_len % j == 0) {
                is_prime = false;
                break;
            }
        }
    } else {
        is_prime = false;
    }

    if (is_prime) {
        if (out_index > 0) {
            out[out_index++] = ' ';
        }
        memcpy(out + out_index, sentence + i - word_len, word_len);
        out_index += word_len;
    }

    out[out_index] = '\0';
}
