#include <stdio.h>
#include <ctype.h>
#include <string.h>

void func0(const char* message, char* out) {
    const char* vowels = "aeiouAEIOU";
    int i, j;
    
    for (i = 0; message[i] != '\0'; ++i) {
        char w = message[i];
        if (islower(w)) {
            w = toupper(w);
        } else if (isupper(w)) {
            w = tolower(w);
        }
        
        for (j = 0; vowels[j] != '\0'; ++j) {
            if (w == vowels[j]) {
                if (j < 10) {
                    w = w + 2;
                }
                break;
            }
        }
        out[i] = w;
    }
    out[i] = '\0';
}
