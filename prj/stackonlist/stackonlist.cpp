#include "stackonlist.h"

StackOnlist::StackOnlist(const StackOnlist& sol){
    head = sol.head;
}

StackOnlist StackOnlist::operator= (const StackOnlist& sol){
    head = sol.head;
    return *this;
}

void StackOnlist::push(Node& n){
    n.prev = head;
    head = &n;
}

void StackOnlist::pop() {
    head = head->prev;
}

Node StackOnlist::top() const {
    return *head;
}

std::string StackOnlist::toString() const {
    std::string str = "";
    Node * a = head;
    while (a != nullptr){
        str += std::to_string(a->value);
        str += " ";
        a = a->prev;
    }
    return str;
}