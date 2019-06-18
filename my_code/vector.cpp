#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
}


MyVec::MyVec() {
}

MyVec::MyVec(const MyVec& v2) {
}

MyVec::~MyVec() {
}

MyVec& MyVec::operator=(const MyVec& v2) {
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
    return true;
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
    return 0;
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
    int j = 0;
    return j;
}
