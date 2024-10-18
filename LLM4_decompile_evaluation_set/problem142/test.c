#include <assert.h>
#include <string.h>
const char* func0(const char* file_name);

int main() {
    assert(strcmp(func0("example.txt"), "Yes") == 0);
    assert(strcmp(func0("1example.dll"), "No") == 0);
    assert(strcmp(func0("s1sdf3.asd"), "No") == 0);
    assert(strcmp(func0("K.dll"), "Yes") == 0);
    assert(strcmp(func0("MY16FILE3.exe"), "Yes") == 0);
    assert(strcmp(func0("His12FILE94.exe"), "No") == 0);
    assert(strcmp(func0("_Y.txt"), "No") == 0);
    assert(strcmp(func0("?aREYA.exe"), "No") == 0);
    assert(strcmp(func0("/this_is_valid.dll"), "No") == 0);
    assert(strcmp(func0("this_is_valid.wow"), "No") == 0);
    assert(strcmp(func0("this_is_valid.txt"), "Yes") == 0);
    assert(strcmp(func0("this_is_valid.txtexe"), "No") == 0);
    assert(strcmp(func0("#this2_i4s_5valid.ten"), "No") == 0);
    assert(strcmp(func0("@this1_is6_valid.exe"), "No") == 0);
    assert(strcmp(func0("this_is_12valid.6exe4.txt"), "No") == 0);
    assert(strcmp(func0("all.exe.txt"), "No") == 0);
    assert(strcmp(func0("I563_No.exe"), "Yes") == 0);
    assert(strcmp(func0("Is3youfault.txt"), "Yes") == 0);
    assert(strcmp(func0("no_one#knows.dll"), "Yes") == 0);
    assert(strcmp(func0("1I563_Yes3.exe"), "No") == 0);
    assert(strcmp(func0("I563_Yes3.txtt"), "No") == 0);
    assert(strcmp(func0("final..txt"), "No") == 0);
    assert(strcmp(func0("final132"), "No") == 0);
    assert(strcmp(func0("_f4indsartal132."), "No") == 0);
    assert(strcmp(func0(".txt"), "No") == 0);
    assert(strcmp(func0("s."), "No") == 0);

    return 0;
}
