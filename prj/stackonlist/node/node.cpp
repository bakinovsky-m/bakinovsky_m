#include "node.h"

Node::Node(const Node& n){
    value = n.value;
    next = n.next;
    prev = n.prev;
}

Node& Node::operator=(const Node& n){
    value = n.value;
    next = n.next;
    prev = n.prev;
}

void Node::setNext(Node * n){
    std::cout << "ALARM set Next" << std::endl;
    next = n;
}

void Node::setPrev(Node * n){
    prev = n;
}

void Node::setValue(int v){
    value = v;
}

int Node::getValue() const{
    if(next != nullptr){
        return value;
    }
    return 0;
}

std::string Node::toString() const{
    std::string str = "";
    str += std::to_string(value);
    // str += "\n";
    // str += std::to_string(next);
    return str;
}