#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
void func0(const char* test, int* freq, int* max_count, char* letters);

bool issame(int* freq1, const char* letters1, int max_count1, int* freq2, const char* letters2, int max_count2) {
    if (max_count1 != max_count2) return false;
    for (int i = 0; letters1[i] != '\0'; i++) {
        if (freq1[letters1[i] - 'a'] != freq2[letters1[i] - 'a']) return false;
    }
    for (int i = 0; letters2[i] != '\0'; i++) {
        if (freq2[letters2[i] - 'a'] != freq1[letters2[i] - 'a']) return false;
    }
    return true;
}

int main() {
    int counts1[26], counts2[26];
    int max_count1, max_count2;
    char letters1[27], letters2[27];

    func0("a b b a", counts1, &max_count1, letters1);
    memset(counts2, 0, sizeof(counts2));
    counts2['a' - 'a'] = 2;
    counts2['b' - 'a'] = 2;
    assert(issame(counts1, letters1, max_count1, counts2, "ab", 2));

    func0("a b c a b", counts1, &max_count1, letters1);
    memset(counts2, 0, sizeof(counts2));
    counts2['a' - 'a'] = 2;
    counts2['b' - 'a'] = 2;
    assert(issame(counts1, letters1, max_count1, counts2, "ab", 2));

    func0("a b c d g", counts1, &max_count1, letters1);
    memset(counts2, 0, sizeof(counts2));
    counts2['a' - 'a'] = counts2['b' - 'a'] = counts2['c' - 'a'] = counts2['d' - 'a'] = counts2['g' - 'a'] = 1;
    assert(issame(counts1, letters1, max_count1, counts2, "abcdg", 1));

    func0("r t g", counts1, &max_count1, letters1);
    memset(counts2, 0, sizeof(counts2));
    counts2['r' - 'a'] = counts2['t' - 'a'] = counts2['g' - 'a'] = 1;
    assert(issame(counts1, letters1, max_count1, counts2, "rtg", 1));

    func0("b b b b a", counts1, &max_count1, letters1);
    memset(counts2, 0, sizeof(counts2));
    counts2['b' - 'a'] = 4;
    assert(issame(counts1, letters1, max_count1, counts2, "b", 4));

    func0("r t g", counts1, &max_count1, letters1);
    memset(counts2, 0, sizeof(counts2));
    counts2['r' - 'a'] = counts2['t' - 'a'] = counts2['g' - 'a'] = 1;
    assert(issame(counts1, letters1, max_count1, counts2, "rtg", 1));

    func0("a", counts1, &max_count1, letters1);
    memset(counts2, 0, sizeof(counts2));
    counts2['a' - 'a'] = 1;
    assert(issame(counts1, letters1, max_count1, counts2, "a", 1));
    
    return 0;
}
