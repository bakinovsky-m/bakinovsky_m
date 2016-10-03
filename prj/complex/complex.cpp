#include <iostream>
#include <string>
#include <cmath>

struct Complex {
    double re = 0.0;
    double im = 0.0;
    const double EPSILON = 0.000000000001;

    Complex() : Complex(0.0, 0.0){}
    Complex(double real): Complex(real, 0.0){}
    Complex(double real, double img) : re(real), im(img){}

    bool operator== (Complex c) {
        if (fabs(re - c.re) <= EPSILON && fabs(im - c.im) <= EPSILON){
            return true;
        } else {
            return false;
        }
    }
    bool operator!= (Complex c) {
        return (!operator==(c));
    }

    Complex operator+ (Complex c){
        return Complex(re + c.re, im + c.im);
    }
    Complex operator- (Complex c){
        return Complex(re - c.re, im - c.im);
    }
    Complex operator* (Complex c){
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }
    Complex operator/ (Complex c){
        double zn = c.re * c.re + c.im * c.im;
        return Complex((re * c.re + im * c.im) / zn, (im * c.re - re * c.im) / zn);
    }
    Complex& operator= (Complex& c) = default;

    std::string toString(){
        std::string res = "";
        res = std::to_string(re);
        res += " + ";
        res += std::to_string(im);
        res += "i";
        return res;
    }
};

void test_binary_operations(){
    Complex a = Complex(5, 3);
    Complex b = Complex(7, 1);
    Complex add = a + b;
    Complex sub = a - b;
    Complex mul = a * b;
    Complex div = a / b;
    std::cout << "Addition: " << add.toString() << ". Must be 12 + 4i" << std::endl;
    std::cout << "Subtraction: " << sub.toString() << ". Must be -2 + 2i" << std::endl;
    std::cout << "Multiplication: " << mul.toString() << ". Must be 32 + 26i" << std::endl;
    std::cout << "Division: " << div.toString() << ". Must be 0.76 - 0.32i" << std::endl;

    Complex c = Complex(0.1, 2);
    Complex d = Complex(0.2, 2);
    if (c == d){
        std::cout << "Equal" << std::endl;
    } else if (c != d) {
        std::cout << "Not equal" << std::endl;
    }
}

int main(){
    test_binary_operations();
}
