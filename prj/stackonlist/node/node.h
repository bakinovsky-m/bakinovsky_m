#ifndef HG_LINKEDLIST_H
#define HG_LINKEDLIST_H

#include <iostream>
#include <string>

class Node{
public:
    Node() = default;
    Node(const int v): value(v){}
    Node(const Node& n);
    Node& operator= (const Node& n);

    void setValue(int v);
    void setNext(Node * n);
    void setPrev(Node * n);

    int getValue() const;//{return value;}
    Node* getNext() const {return next;}
    Node* getPrev() const {return prev;}

    std::string toString() const;
private:
    int value = 0;
    Node * next = nullptr;
    Node * prev = nullptr;
};

#endif