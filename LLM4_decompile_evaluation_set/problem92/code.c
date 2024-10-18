#include <stdio.h>
#include <string.h>
#include <ctype.h>

int func0(const char *S) {
    int isstart = 1;
    int isi = 0;
    int sum = 0;
    for (int i = 0; S[i] != '\0'; i++) {
        if (isspace(S[i]) && isi) {
            isi = 0;
            sum += 1;
        }
        if (S[i] == 'I' && isstart) {
            isi = 1;
        } else if (!isspace(S[i])) {
            isi = 0;
        }
        if (!isspace(S[i])) {
            isstart = 0;
        }
        if (S[i] == '.' || S[i] == '?' || S[i] == '!') {
            isstart = 1;
        }
    }
    return sum;
}
