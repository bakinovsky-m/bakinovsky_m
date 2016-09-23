#include <iostream>
#include <cstdint>
#include <string>
#include "nod.h"
class Rational {
public:
    Rational();
    Rational(const int32_t num) : num_(num){};
    Rational(const int32_t num, const int32_t denum){
        num_ = num;
        denum_ = denum;
        normalize();
    }
    Rational operator+ (const Rational s){
        return Rational ((num_*s.denum_ + denum_*s.num_), denum_*s.denum_);
    }
    Rational operator- (const Rational s){
        return Rational ((num_*s.denum_ - denum_*s.num_), denum_*s.denum_);
    }
    Rational operator* (const Rational s){
        return Rational (num_*s.num_, denum_*s.denum_);
    }
    Rational operator/ (const Rational s){
        return Rational (num_*s.denum_, denum_*s.num_);
    }
    Rational& operator= (const Rational& s) = default;
    void normalize();
    double toDouble(){
            double n = num_;
            double dn = denum_;
            return n / dn;
    }

    std::string toString(){
        std::string str = "";
        str = std::to_string(num_);
        str += "/";
        str += std::to_string(denum_);
        return str;
    }
private:
    int32_t num_ = 0;
    int32_t denum_ = 1;
};

void Rational::normalize(){
    int nod_ = nod(num_, denum_);
    if (num_/nod_ == denum_/nod_) {
        num_ = num_/nod_;
        denum_ = 1;
    } else {
        num_ = num_/nod_;
        denum_ = denum_/nod_;
    }
}

void test(){
    Rational a = Rational(1, 2);
    Rational b = Rational(6, 4);
    std::cout << (a + b).toString() << std::endl;
}

int main(){
    test();
}
