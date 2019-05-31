#include <cassert>
#include "../my_code/pointers.h"

using namespace std;

int main() {
    int n = 0;
    inc_by_value(n);
    assert(n == 0);
    inc_with_pointer(&n);
    assert(n == 1);
    inc_with_reference(n);
    assert(n == 2);
    return 0;
}
