#include <stdio.h>
#include <string.h>

const char *func0(const char *s1, const char *s2) {
    int count = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i;
    int can = 1;

    for (i = 0; i < len1; i++) {
        if (s1[i] == '(') count++;
        if (s1[i] == ')') count--;
        if (count < 0) can = 0;
    }
    for (i = 0; i < len2; i++) {
        if (s2[i] == '(') count++;
        if (s2[i] == ')') count--;
        if (count < 0) can = 0;
    }
    if (count == 0 && can) return "Yes";

    count = 0;
    can = 1;

    for (i = 0; i < len2; i++) {
        if (s2[i] == '(') count++;
        if (s2[i] == ')') count--;
        if (count < 0) can = 0;
    }
    for (i = 0; i < len1; i++) {
        if (s1[i] == '(') count++;
        if (s1[i] == ')') count--;
        if (count < 0) can = 0;
    }
    if (count == 0 && can) return "Yes";

    return "No";
}
