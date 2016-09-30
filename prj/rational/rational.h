#ifndef HG_RATIONAL_H
#define HG_RATIONAL_H

#include <iostream>
#include <cstdint>
#include <string>
#include <exception>

#include "nod.h"

class Rational {
public:
    Rational();
    Rational(const int32_t num);
    Rational(const int32_t num, const int32_t denum);

    Rational operator+ (const Rational s);
    Rational operator- (const Rational s);
    Rational operator* (const Rational s);
    Rational operator/ (const Rational s);
    Rational& operator= (const Rational& s);
    void normalize();
    double toDouble();
    std::string toString();
private:
    int32_t num_ = 0;
    int32_t denum_ = 1; 
};
#endif
