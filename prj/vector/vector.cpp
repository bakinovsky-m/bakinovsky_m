#include "vector.h"

Vector::Vector(){
    length = 0;
}

Vector::Vector(int* arr, const int size){
    std::cout << arr << std::endl;
    ptr = new int[size];
    ptr = arr;
    std::cout << ptr << std::endl;
    length = size;
}

Vector::~Vector(){
    delete [] ptr;
}

std::string Vector::toString() const {
    std::string str = "";
    str += "[";
    for(int i = 0; i < length; i++){
        str += std::to_string(*(ptr + i));
        str += " ";
    }
    str += "]";
    return str;
}

int Vector::len() const {
    return length;
}