#include <iostream>
#include "date.h"

using namespace std;

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

ostream & operator<<(ostream & os, const Date & d) {
	os << d.month << "/" << d.day << "/" << d.year;
	return os;
}