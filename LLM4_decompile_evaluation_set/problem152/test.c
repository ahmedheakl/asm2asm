#include <assert.h>
long long func0(float lst[], int lst_size);

int main() {
    assert(func0((float[]){}, 0) == 0);
    assert(func0((float[]){5, 4}, 2) == 25);
    assert(func0((float[]){0.1, 0.2, 0.3}, 3) == 0);
    assert(func0((float[]){-10, -20, -30}, 3) == 0);
    assert(func0((float[]){-1, -2, 8}, 3) == 0);
    assert(func0((float[]){0.2, 3, 5}, 3) == 34);
    
    long long odd_sum = 0;
    float lst[200];
    int lst_size = 0;

    for (int i = -99; i < 100; i += 2) {
        lst[lst_size++] = i + 0.0f;
        if (i > 0 && i % 2 == 1) odd_sum += i * i;
    }

    assert(func0(lst, lst_size) == odd_sum);

    return 0;
}
