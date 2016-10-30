#include <iostream>
#include "matrix2d.h"

int main(){
    Matrix2d a = Matrix2d(3);
    Matrix2d b = a;

    int arr[] = {1,2,3,4,5,6,7,8,9};
    Matrix2d c = Matrix2d(arr, 3, 3);

    std::cout << a.toString() << std::endl;
    std::cout << b.toString() << std::endl;
    std::cout << c.toString() << std::endl;

    if (a == b){
        std::cout << "Equal" << std::endl;
    }

    return 0;
}