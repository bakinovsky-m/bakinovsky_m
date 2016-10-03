#include <iostream>
#include <string>
#include <cmath>

struct Complex  {
    double re = 0.0;
    double im = 0.0;
    const double EPSILON = 0.000000000001;

    Complex();
    Complex(double real);
    Complex(double real, double img);
    bool operator==(Complex c);
    bool operator!= (Complex c);
    Complex operator+ (Complex c);
    Complex operator- (Complex c);
    Complex operator* (Complex c);
    Complex operator/ (Complex c);
    std::string toString();
    Complex& operator= (Complex& c) = default;
};

