#include "rational.h"

Rational::Rational(){}
Rational::Rational(const int32_t num) : num_(num){};
Rational::Rational(const int32_t num, const int32_t denum){
        num_ = num;
        denum_ = denum;
        normalize();
}
Rational Rational::operator+ (const Rational s){
        return Rational ((num_*s.denum_ + denum_*s.num_), denum_*s.denum_);
}
Rational Rational::operator- (const Rational s){
        return Rational ((num_*s.denum_ - denum_*s.num_), denum_*s.denum_);
}
Rational Rational::operator* (const Rational s){
        return Rational (num_*s.num_, denum_*s.denum_);
}
Rational Rational::operator/ (const Rational s){
        return Rational (num_*s.denum_, denum_*s.num_);
}
Rational& Rational::operator= (const Rational& s) = default;

double Rational::toDouble(){
            double n = num_;
            double dn = denum_;
            return n / dn;
    }

std::string Rational::toString(){
        std::string str = "";
        str = std::to_string(num_);
        str += "/";
        str += std::to_string(denum_);
        return str;
    }

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
