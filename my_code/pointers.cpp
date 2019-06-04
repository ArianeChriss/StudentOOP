#include <iostream>
#include "pointers.h"

using namespace std;

void inc_by_value(int n) {
	++n;
}


void inc_with_pointer(int* iptr) {
	++(*iptr);
}


void inc_with_reference(int& n) {
	++n;
}


Thing** create_array_of_things(int n) {
	Thing** things = new Thing*[n];
	for (int i = 0; i < n; ++i) {
		*(things + i) = new Thing(i);
	}
	return things;
}

void print_all_things(Thing** things, int n) {
	for (int i = 0; i < n; ++i) {
		cout << (*(things + i))->val << endl;
	}
}

void double_all_things(Thing** things, int n) {
	for (int i = 0; i < n; ++i) {
		(*(things + i))->val = ((*(things + i))->val) * 2;
	}
}

void delete_all_things(Thing** things, int n) {
	for (int i = n - 1; i >= 0; --i) {
		*(things + i) = nullptr;
	}
}


void assignTA(Student* s, Student* ta) {
	s->ta = ta;
}

void printTAs(vector<Student*> students) {
	for (Student* s : students) {
		if (s->ta) {
			cout << s->name << " has TA " << (s->ta)->name << endl;
		}
		else {
			cout << s->name << " has no TA" << endl;
		}
	}
}