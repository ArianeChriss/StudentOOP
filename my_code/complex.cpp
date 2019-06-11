#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
	if (c1.get_real() == c2.get_real() && c1.get_imag() == c2.get_imag()) return true;
	else return false;
}

bool operator!= (const Complex& c1, const Complex& c2) {
	if (c1.get_real() == c2.get_real() && c1.get_imag() == c2.get_imag()) return false;
	else return true;
}

ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
	os << c.get_real() << c.get_imag();
	return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
	double real;
	double imag;
	cin >> real >> imag;
	c = Complex(real, imag);
	return is;
}


Complex::operator bool() const {
	if (real || imag) return true;
	else return false;
}

Complex& Complex::operator++() {
	++real;
	return *this;
}

Complex Complex::operator++(int dummy) {
	double temp = real;
	real++;
	return Complex(temp, imag);
}

Complex& Complex::operator--() {
	--real;
	return *this;
}

Complex Complex::operator--(int dummy) {
	double temp = real;
	real--;
	return Complex(temp, imag);
}

double Complex::get_real() const {
	return real;
}

double Complex::get_imag() const {
	return imag;
}

Complex Complex::operator*(const int i) {
	real = real * i;
	return *this;
}

Complex Complex::operator-=(const Complex& c) {
	real -= c.get_real();
	imag -= c.get_imag();
	return *this;
}

/*
 * `+` adds real to real, and complex to complex.
 * */
Complex operator+(const Complex& c1, const Complex& c2) {
	return Complex(c1.get_real() + c2.get_real(), c1.get_imag() + c2.get_imag());
}

/*
 * `-` subtracts real from real, and complex from complex.
 * */
Complex operator-(const Complex& c1, const Complex& c2) {
	return Complex(c1.get_real() - c2.get_real(), c1.get_imag() - c2.get_imag());
}