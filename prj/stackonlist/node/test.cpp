#include <iostream>

#include "node.h"

int main(){
    Node n1;
    n1.setValue(5);
    Node n2;
    n1.setNext(&n2);

    return 0;
}