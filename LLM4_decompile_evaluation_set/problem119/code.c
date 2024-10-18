#include <stdio.h>
#include <string.h>

char *func0(const char *word) {
    static char out[2] = {0};
    const char *vowels = "AEIOUaeiou";
    size_t len = strlen(word);
    
    for (int i = len - 2; i >= 1; i--) {
        if (strchr(vowels, word[i]) && !strchr(vowels, word[i + 1]) && !strchr(vowels, word[i - 1])) {
            out[0] = word[i];
            return out;
        }
    }
    out[0] = '\0';
    return out;
}
