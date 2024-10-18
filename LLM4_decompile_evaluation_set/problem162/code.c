#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* func0(char *s){
    int nletter = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (isalpha((unsigned char)s[i])) {
            if (isupper((unsigned char)s[i])) s[i] = tolower((unsigned char)s[i]);
            else if (islower((unsigned char)s[i])) s[i] = toupper((unsigned char)s[i]);
        } else {
            nletter += 1;
        }
    }
    if (nletter == length) {
        for (int i = 0; i < length / 2; i++) {
            char temp = s[i];
            s[i] = s[length - i - 1];
            s[length - i - 1] = temp;
        }
    }
    return s;
}
