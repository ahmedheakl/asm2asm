#include <assert.h>
int func0(const char **operato, const int *operand, int operato_size, int operand_size);

int main() {
    const char *operators1[] = {"**", "*", "+"};
    int operands1[] = {2, 3, 4, 5};
    assert(func0(operators1, operands1, 3, 4) == 37);

    const char *operators2[] = {"+", "*", "-"};
    int operands2[] = {2, 3, 4, 5};
    assert(func0(operators2, operands2, 3, 4) == 9);

    const char *operators3[] = {"//", "*"};
    int operands3[] = {7, 3, 4};
    assert(func0(operators3, operands3, 2, 3) == 8);

    return 0;
}
