#include <cassert>
#include "../my_code/hello.h"

using namespace std;

int main() {
	int ret = sayHello();
    assert(ret == 0);
    return ret;

	//changed for a third time
}
