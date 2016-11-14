#include "stackonlist.h"

StackOnlist::StackOnlist(const StackOnlist& sol){
    head = sol.head;
    tail = sol.tail;
}

StackOnlist StackOnlist::operator= (const StackOnlist& sol){
    head = sol.head;
    tail = sol.tail;
}

void StackOnlist::push(Node& n){
    n.setPrev(head);
    if (head != nullptr){
        head->setNext(&n);
        head = &n;
    }
}

void StackOnlist::pop() {
    head->getPrev()->setNext(nullptr);
}

Node StackOnlist::top(){
    return *head;
}

std::string StackOnlist::toString() const {
    std::string str = "";
    str += std::to_string((*head).getValue());
    return str;
}