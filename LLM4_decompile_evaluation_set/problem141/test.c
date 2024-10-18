#include <assert.h>
#include <string.h>
void func0(const char *text, char *out);

int main() {
    char output[100];

    func0("Example", output);
    assert(strcmp(output, "Example") == 0);

    func0("Mudasir Hanif ", output);
    assert(strcmp(output, "Mudasir_Hanif_") == 0);

    func0("Yellow Yellow  Dirty  Fellow", output);
    assert(strcmp(output, "Yellow_Yellow__Dirty__Fellow") == 0);

    func0("Exa   mple", output);
    assert(strcmp(output, "Exa-mple") == 0);

    func0("   Exa 1 2 2 mple", output);
    assert(strcmp(output, "-Exa_1_2_2_mple") == 0);

    return 0;
}
