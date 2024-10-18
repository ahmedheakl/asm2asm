#include <assert.h>
int func0(const char *date);

int main() {
    assert(func0("03-11-2000") == 1);
    assert(func0("15-01-2012") == 0);
    assert(func0("04-0-2040") == 0);
    assert(func0("06-04-2020") == 1);
    assert(func0("01-01-2007") == 1);
    assert(func0("03-32-2011") == 0);
    assert(func0("") == 0);
    assert(func0("04-31-3000") == 0);
    assert(func0("06-06-2005") == 1);
    assert(func0("21-31-2000") == 0);
    assert(func0("04-12-2003") == 1);
    assert(func0("04122003") == 0);
    assert(func0("20030412") == 0);
    assert(func0("2003-04") == 0);
    assert(func0("2003-04-12") == 0);
    assert(func0("04-2003") == 0);

    return 0;
}
