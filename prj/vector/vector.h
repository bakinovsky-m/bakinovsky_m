#ifndef HG_VECTOR_H
#define HG_VECTOR_H

#include <iostream>
#include <string>

class Vector {
public:
    Vector();
    Vector(int* arr, const int size);
    ~Vector();

    std::string toString() const;
    int len() const;
private:
    int buffer = 0;
    int length = 0;
    int *ptr = nullptr;
};

#endif