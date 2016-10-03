#include "complex.h"

Complex::Complex() : Complex(0.0, 0.0){}
Complex::Complex(double real): Complex(real, 0.0){}
Complex::Complex(double real, double img) : re(real), im(img){}

bool Complex::operator== (Complex c) {
    if (fabs(re - c.re) <= EPSILON && fabs(im - c.im) <= EPSILON){
        return true;
    } else {
        return false;
    }
}
bool Complex::operator!= (Complex c) {
    return (!operator==(c));
}

Complex Complex::operator+ (Complex c){
    return Complex(re + c.re, im + c.im);
}
Complex Complex::operator- (Complex c){
    return Complex(re - c.re, im - c.im);
}
Complex Complex::operator* (Complex c){
    return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
}
Complex Complex::operator/ (Complex c){
    double zn = c.re * c.re + c.im * c.im;
    return Complex((re * c.re + im * c.im) / zn, (im * c.re - re * c.im) / zn);
}

std::string Complex::toString(){
    std::string res = "";
    res = std::to_string(re);
    res += " + ";
    res += std::to_string(im);
    res += "i";
    return res;
}