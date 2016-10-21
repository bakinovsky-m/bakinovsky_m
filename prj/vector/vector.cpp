#include "vector.h"

// constructors + destructor
Vector::Vector(const int size){
    length = size;
    ptr = new int[length];
}

Vector::Vector(int* arr, const int size){
    length = size;
    ptr = new int[length];
    for(int i = 0; i < length; i++){
        ptr[i] = arr[i];
    }
}

Vector::~Vector(){
    delete [] ptr;
}

Vector::Vector(const Vector& v){ // copy 
    length = v.length;
    ptr = new int[length];
    for(int i = 0; i < length; i++){
        ptr[i] = v.ptr[i];
    }
}

// overrided operators
Vector& Vector::operator= (const Vector& v){
    length = v.length;
    ptr = new int[length];
    for(int i = 0; i < length; i++){
        ptr[i] = v.ptr[i];
    }
}

int Vector::operator[] (const int ind) const{
    std::cout << "int" << std::endl;
    return ptr[ind];
}

int& Vector::operator[] (const int ind){
    std::cout << "int&" << std::endl;
    return ptr[ind];
}

bool Vector::operator== (const Vector& v) const{
    if (length != v.length) return false;
    for (int i = 0; i < length; i++){
        if(ptr[i] != v.ptr[i]) return false;
    }
    return true;
}

bool Vector::operator!= (const Vector& v) const {
    return(!operator==(v));
}

// other methods
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