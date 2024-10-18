#include <stdio.h>
#include <string.h>

const char* func0(const char* numbers) {
    int count[10] = {0};
    const char* numto[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int index, i, j, k;
    static char out[1000]; 
    char current[6]; 

    index = 0;
    if (*numbers) {
        do {
            for (i = 0; numbers[i] != ' ' && numbers[i] != '\0'; ++i) {
                current[i] = numbers[i];
            }
            current[i] = '\0';
            for (j = 0; j < 10; ++j) {
                if (strcmp(current, numto[j]) == 0) {
                    count[j]++;
                    break;
                }
            }
            numbers += i + 1;
        } while (numbers[-1]);
    }

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < count[i]; ++j) {
            for (k = 0; numto[i][k] != '\0'; ++k, ++index) {
                out[index] = numto[i][k];
            }
            out[index++] = ' '; 
        }
    }

    if (index > 0) {
        out[index - 1] = '\0'; 
    } else {
        out[0] = '\0';
    }

    return out;
}
