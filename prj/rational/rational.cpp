#include <iostream>
#include <cstdint>
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

    void print(){
        if (denum_ == 1){
            std::cout << num_ << std::endl;
        } else {
            std::cout << num_ << "/" << denum_ << std::endl;
        }
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

int main(){
    Rational a = Rational(1,2);
    Rational b = Rational(2,4);
    Rational sum = a + b;
    sum.print();
    sum.print();
}
