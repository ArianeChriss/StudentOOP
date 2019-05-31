#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "../my_code/basics.h"

using namespace std;

int main() {

    say("Hello!");

    int j = 8;
    inc_pass_copy(j);
    cout << "j = " << j << endl;
    inc_pass_ref(j);
    cout << "j = " << j << endl;
    // Put this assertion back once you've written code:
    // assert(j == 9);

    int test_num = 10;
    int ret = square(test_num);
    assert(ret == (test_num * test_num));

    double test_dbl = 2.5;
    double dret = square(test_dbl);
    cout << "2.5 squared = " << dret << endl;
    assert(dret == (test_dbl * test_dbl));
    cout << "Int value of dret = " << (int)dret << endl;

    ret = my_abs(test_num);
    assert(ret == test_num);
    ret = 77;
    ret = my_abs(-test_num);
    assert(ret == test_num);

    ret = sum(test_num);
    assert(ret == 45);
    ret = sum2(test_num);
    assert(ret == 45);

    vector<int> v = { 0 };
    fill_vector(v, test_num);
    print_vector(v);
    cout << "v[1] = " << v[1] << endl;

    coord pos;
    pos.x = 7;
    pos.y = 8;
    print_coords(pos);

    char c = 'A';
    string s = "C++ strings are collections of chars.";
    s += '!';
    pull_apart_string(s);
    assert(c < s[4]);
    c++;
    cout << "c = " << c << endl;
    cout << "Int val of c = " << (int)c << endl;

    say("Goodbye!");
    return 0;
}
