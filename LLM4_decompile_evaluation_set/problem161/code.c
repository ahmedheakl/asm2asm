#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int func0(const char **operato, const int *operand, int operato_size, int operand_size) {
    int *num = (int*)malloc(operand_size * sizeof(int));
    int *posto = (int*)malloc(operand_size * sizeof(int));
    for (int i = 0; i < operand_size; i++) {
        num[i] = operand[i];
        posto[i] = i;
    }
    for (int i = 0; i < operato_size; i++) {
        if (strcmp(operato[i], "**") == 0) {
            while (posto[posto[i]] != posto[i]) posto[i] = posto[posto[i]];
            while (posto[posto[i + 1]] != posto[i + 1]) posto[i + 1] = posto[posto[i + 1]];
            num[posto[i]] = pow(num[posto[i]], num[posto[i + 1]]);
            posto[i + 1] = posto[i];
        }
    }
    for (int i = 0; i < operato_size; i++) {
        if (strcmp(operato[i], "*") == 0 || strcmp(operato[i], "//") == 0) {
            while (posto[posto[i]] != posto[i]) posto[i] = posto[posto[i]];
            while (posto[posto[i + 1]] != posto[i + 1]) posto[i + 1] = posto[posto[i + 1]];
            if (strcmp(operato[i], "*") == 0)
                num[posto[i]] *= num[posto[i + 1]];
            else
                num[posto[i]] /= num[posto[i + 1]];
            posto[i + 1] = posto[i];
        }
    }
    for (int i = 0; i < operato_size; i++) {
        if (strcmp(operato[i], "+") == 0 || strcmp(operato[i], "-") == 0) {
            while (posto[posto[i]] != posto[i]) posto[i] = posto[posto[i]];
            while (posto[posto[i + 1]] != posto[i + 1]) posto[i + 1] = posto[posto[i + 1]];
            if (strcmp(operato[i], "+") == 0)
                num[posto[i]] += num[posto[i + 1]];
            else
                num[posto[i]] -= num[posto[i + 1]];
            posto[i + 1] = posto[i];
        }
    }
    int result = num[0];
    free(num);
    free(posto);
    return result;
}
