#include <iostream>

#include "stackonlist.h"

int main(){
    Node n1 = Node(5);
    Node n2 = Node(6);
    StackOnlist sol;
    sol.push(n1);
    std::cout << sol.toString() << std::endl;
    sol.push(n2);
    std::cout << sol.toString() << std::endl;

    std::cout << "n1.prev" << std::endl;
    std::cout << n1.prev << std::endl;

    std::cout << "n2.prev" << std::endl;
    std::cout << n2.prev << std::endl;

    std::cout << "n1" << std::endl;
    std::cout << &n1 << std::endl;
    std::cout << "n2" << std::endl;
    std::cout << &n2 << std::endl;
    return 0;
}