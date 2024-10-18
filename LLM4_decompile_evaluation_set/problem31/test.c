#include <assert.h>
#include <math.h>
float* func0(const float* l, int count, int* out_count);

// Helper function to compare two arrays of floats
int issame(const float* a, int a_count, const float* b, int b_count) {
    if (a_count != b_count) return 0;
    for (int i = 0; i < a_count; i++) {
        if (fabs(a[i] - b[i]) > 1e-4) return 0;
    }
    return 1;
}

int main() {
    float* result;
    int count;

    result = func0((float[]){-1, -2, 4, 5, 6}, 5, &count);
    assert(issame(result, count, (float[]){4, 5, 6}, 3));
    free(result);

    result = func0((float[]){5, 3, -5, 2, 3, 3, 9, 0, 123, 1, -10}, 11, &count);
    assert(issame(result, count, (float[]){5, 3, 2, 3, 3, 9, 123, 1}, 8));
    free(result);

    result = func0((float[]){-1, -2}, 2, &count);
    assert(issame(result, count, (float[]){}, 0));
    free(result);

    result = func0((float[]){}, 0, &count);
    assert(issame(result, count, (float[]){}, 0));
    free(result);

    return 0;
}
