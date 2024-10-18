#include <stdio.h>
#include <string.h>

void func0(const char* class_name, const char** extensions, int ext_count, char* output) {
    int max_strength = -1000;
    const char* strongest = NULL;
    for (int i = 0; i < ext_count; i++) {
        const char* extension = extensions[i];
        int strength = 0;
        for (int j = 0; extension[j] != '\0'; j++) {
            char chr = extension[j];
            if (chr >= 'A' && chr <= 'Z') strength++;
            if (chr >= 'a' && chr <= 'z') strength--;
        }
        if (strength > max_strength) {
            max_strength = strength;
            strongest = extension;
        }
    }
    sprintf(output, "%s.%s", class_name, strongest);
}
