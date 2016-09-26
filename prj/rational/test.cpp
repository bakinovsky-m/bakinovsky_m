#include "rational.h"

int main(){
    Rational a = Rational(1, 2);
    Rational b = Rational(2, 4);
    std::cout << (a + b).toString() << std::endl;
    return 0;
}
