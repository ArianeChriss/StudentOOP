#ifndef COMPLEX_H
#define COMPLEX_H


class Complex {
    friend std::ostream& operator<< (std::ostream& os, const Complex& c);
    friend std::istream& operator>> (std::istream& is, Complex& c);

    /*
     * The equality operator should be a friend since it is binary
     * and symmetrical.
     * */

 public:
    /*
     * Our sole constructor takes defaults of 0 for both `real` and
     * `imag`, so can be called with no arguments.
     * */
	 Complex(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    /*
     * The `bool` operator tests to see if either
     * data member is non-zero, and returns `true`
     * if so.
     * */
    explicit operator bool() const;
    
    /*
     * Get the real component:
     * */
    double get_real() const;
    
    /*
     * Get the imaginary component:
     * */
    double get_imag() const;

    /*
     * This overload is pre-increment: pretty straightforward:
     * bump up the `real` member, and return myself.
     * Of course, it's not obvious that this is what incrementing
     * a complex number *should* do: but we are teaching here,
     * not writing a production Complex class.
     * */
    Complex& operator++();

    /*
     * Post-increment is more complicated than pre: first
     * of all, it takes a dummy int parameter (unused)
     * just so the compiler can tell which inc operator is which.
     * Secondly, since it returns the value from *before*
     * the increment, we must store that in a temp var.
     * */
    Complex operator++(int dummy);

    /*
     * This overload is pre-decrement: pretty straightforward:
     * decrease the `real` member, and return myself.
     * Of course, it's not obvious that this is what decrementing
     * a complex number *should* do: but we are teaching here,
     * not writing a production Complex class.
     * */
    Complex& operator--();

    /*
     * Post-decrement is more complicated than pre: first
     * of all, it takes a dummy int parameter (unused)
     * just so the compiler can tell which inc operator is which.
     * Secondly, since it returns the value from *before*
     * the decrement, we must store that in a temp var.
     * */
    Complex operator--(int dummy);

	Complex operator-=(const Complex& c);

    /*
     * Let's do multiplication by a scalar:
     * */
    Complex operator*(const int i);

 private:
    double real;
    double imag;
};


bool operator== (const Complex& c1, const Complex& c2);
bool operator!= (const Complex& c1, const Complex& c2);

Complex operator+(const Complex& c1, const Complex& c2);
Complex operator-(const Complex& c1, const Complex& c2);

#endif
