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
    Rational normalize();
    double toDouble(){
            double n = num_;
            double dn = denum_;
            return n / dn;
    }

    void print(){
        std::cout << num_ << "/" << denum_ << std::endl;
    }
private:
    int32_t num_ = 0;
    int32_t denum_ = 1;
};

Rational Rational::normalize(){
    int nod_ = nod(num_, denum_);
    std::cout << nod_ << std::endl;
    return Rational (num_/nod_, denum_/nod_);
}

int main(){
    Rational a = Rational(1,2);
    Rational b = Rational(2,4);
    Rational sum = a + b;
    sum.print();
    sum.normalize();
    sum.print();
}

