#ifndef HG_STACKONLIST_H
#define HG_STACKONLIST_H

#include <iostream>
#include <string>

struct Node{
    Node(const int v): value(v){}
    int value = 0;
    Node * prev = nullptr;
};

class StackOnlist{
public:
    StackOnlist() = default;
    StackOnlist(const StackOnlist& sol);
    StackOnlist operator= (const StackOnlist& sol);

    void push(Node& n);
    void pop();
    Node top() const;

    std::string toString() const;
private:
    Node * head = nullptr;
};

#endif