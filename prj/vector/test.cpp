#include <iostream>

#include "vector.h"

int main(){
    int q[] = {1,2,3,4,5};
    Vector a = Vector(q, 5);
    
    // std::cout << a.len() << std::endl;
    std::cout << a.toString() << std::endl;
}