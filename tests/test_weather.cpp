#include <cassert>
#include <iostream>
#include "../my_code/weather.h"

using namespace std;

int main() {
    GPS loc = GPS(46.3, 67.2);
    Weather irkutsk = Weather("Irkutsk", loc);
    cout << irkutsk << endl;
}
