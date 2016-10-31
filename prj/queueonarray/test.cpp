#include <iostream>

#include "queueonarray.h"

int main(){
    QueueOnArray a = QueueOnArray(5);
    std::cout << a.toString() << std::endl;
    a.push(7);
    std::cout << a.toString() << std::endl;
    a.push(2);
    std::cout << a.toString() << std::endl;
    a.pop();
    std::cout << a.toString() << std::endl;

    std::cout << sizeof(a) << std::endl;    

    QueueOnArray b = QueueOnArray(5);
    std::cout << "b: " << b.toString() << std::endl;
    for (int i = 0; i < 5; i++){
        b.push(1);
        std::cout << b.toString() << std::endl;
    }
    b.pop();
    std::cout << b.toString() << std::endl;
    b.push(2);
    std::cout << b.toString() << std::endl;
    b.resize(7);
    std::cout << b.toString() << std::endl;
    a = b;
    return 0;
}