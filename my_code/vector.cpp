#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}


MyVec::MyVec() : data(new int[1]), sz(0), capacity(1) {}

MyVec::MyVec(const MyVec& v2) {
	capacity = v2.capacity;
	sz = v2.sz;
	data = new int[v2.capacity];
	for (int i = 0; i < v2.size(); ++i) {
		data[i] = v2.data[i];
	}
}

MyVec::~MyVec() {
	delete[] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
	if (v2.size() > sz) {
		for (int i = 0; i < v2.size(); ++i) {
			data[i] = v2[i];
		}
		delete[] & data[v2.size()];									// deletes unneeded remainder of array
	}
	else {
		int* old = data;
		data = new int[v2.size()];
		delete[] old;
		for (int i = 0; i < v2.size(); ++i) {
			data[i] = v2[i];
			capacity = v2.size();
			sz = v2.size();
		}
	}
	return *this;
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
	if (v1.size() != v2.size()) return false;
	else {
		for (int i = 0; i < v2.size(); ++i) {
			if (v1[i] != v2[i]) return false;
		}
	}
	return true;
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
	if (sz != capacity) {
		data[sz] = val;
		sz++;
	}
	else {
		int* old = data;
		data = new int[2 * capacity];
		for (int i = 0; i < sz; ++i) {
			data[i] = old[i];
		}
		data[sz] = val;
		capacity *= 2;
		sz++;
		delete[] old;
	}
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
	return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
	return data[i];
}