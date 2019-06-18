#include <cassert>
#include <iostream>
#include "../my_code/vector.h"

using namespace std;

int copy_vector(MyVec v) {
    MyVec local_v = v;
    return local_v.size();
}

int main() {
    MyVec v = MyVec();
    for (int i = 0; i < 200; i++) {
        v.push_back(i);
        copy_vector(v);
    }
    assert(v[199] == 199);
    for (int i = 0; i < 200; i++) {
        v[i] *= 2;
    }
    assert(v[199] == 398);
    MyVec v3;
    for (int i = 9; i < 100; i += 9) {
        v3.push_back(i);
    }
    assert(v3[1] == 18);

    MyVec v2 = v;
    print_vector(v2);
    assert(v2 == v);

    v2 = v3;
    print_vector(v2);
    assert(v2 == v3);
}
