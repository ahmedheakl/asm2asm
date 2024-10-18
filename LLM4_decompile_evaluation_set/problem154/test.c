#include <assert.h>
#include <string.h>
void func0(const char* class_name, const char** extensions, int ext_count, char* output);

int main() {
    char result[50];

    func0("Watashi", (const char* []){"tEN", "niNE", "eIGHt8OKe"}, 3, result);
    assert(strcmp(result, "Watashi.eIGHt8OKe") == 0);

    func0("Boku123", (const char* []){"nani", "NazeDa", "YEs.WeCaNe", "32145tggg"}, 4, result);
    assert(strcmp(result, "Boku123.YEs.WeCaNe") == 0);

    func0("__YESIMHERE", (const char* []){"t", "eMptY", "(nothing", "zeR00", "NuLl__", "123NoooneB321"}, 6, result);
    assert(strcmp(result, "__YESIMHERE.NuLl__") == 0);

    func0("K", (const char* []){"Ta", "TAR", "t234An", "cosSo"}, 4, result);
    assert(strcmp(result, "K.TAR") == 0);

    func0("__HAHA", (const char* []){"Tab", "123", "781345", "-_-"}, 4, result);
    assert(strcmp(result, "__HAHA.123") == 0);

    func0("YameRore", (const char* []){"HhAas", "okIWILL123", "WorkOut", "Fails", "-_-"}, 5, result);
    assert(strcmp(result, "YameRore.okIWILL123") == 0);

    func0("finNNalLLly", (const char* []){"Die", "NowW", "Wow", "WoW"}, 4, result);
    assert(strcmp(result, "finNNalLLly.WoW") == 0);

    func0("_", (const char* []){"Bb", "91245"}, 2, result);
    assert(strcmp(result, "_.Bb") == 0);

    func0("Sp", (const char* []){"671235", "Bb"}, 2, result);
    assert(strcmp(result, "Sp.671235") == 0);
    
    return 0;
}
