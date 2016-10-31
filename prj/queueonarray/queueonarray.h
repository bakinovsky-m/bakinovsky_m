#include <string>
// #include <iostream>

class QueueOnArray{
public:
    QueueOnArray() = default;
    QueueOnArray(const QueueOnArray& qoa);
    QueueOnArray operator=(const QueueOnArray& qoa);

    QueueOnArray(const int size);

    ~QueueOnArray();

    void push(const int);
    void pop();
    int top() const;

    void resize(const int newSize);

    std::string toString() const;
private:
    int size = 0;
    int * array = nullptr;
    int head = 0;
    int tail = 0; 

    void defragment();
};