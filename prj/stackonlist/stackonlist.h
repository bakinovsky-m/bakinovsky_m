#ifndef HG_STACKONLIST_H
#define HG_STACKONLIST_H

#include "node/node.h"

class StackOnlist{
public:
    StackOnlist() = default;
    StackOnlist(const StackOnlist& sol);
    StackOnlist operator= (const StackOnlist& sol);

    void push(Node& n);
    void pop();
    Node top();

    std::string toString() const;
private:
    Node * head = nullptr;
    Node * tail = nullptr;
};

#endif