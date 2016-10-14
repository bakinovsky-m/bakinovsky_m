#ifndef HG_COMPLEX_H
#define HG_COMPLEX_H

#include <iostream>
#include <string>
#include <cmath>

struct Complex  {
    double re = 0.0;
    double im = 0.0;
    const double EPSILON = 0.000000000001;

    Complex();
    Complex(const double real);
    Complex(const double real, const double img);
    bool operator==(const Complex c) const;
    bool operator!= (const Complex c) const;
    Complex operator+ (const Complex c) const;
    Complex operator- (const Complex c) const;
    Complex operator* (const Complex c) const;
    Complex operator/ (const Complex c) const;
    std::string toString() const;
    Complex& operator= (Complex& c) = default;
};
#endif