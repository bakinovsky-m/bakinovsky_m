#include "queueonarray.h"

QueueOnArray::QueueOnArray(const QueueOnArray& qoa){
    size = qoa.size;
    array = new int[size];
    for (int i = 0; i < size; i++){
        array[i] = qoa.array[i];
    }
    head = qoa.head;
    tail = qoa.tail;
}

QueueOnArray& QueueOnArray::operator=(const QueueOnArray& qoa){
    size = qoa.size;
    delete[] array;
    array = new int[size];
    for (int i = 0; i < size; i++){
        array[i] = qoa.array[i];
    }
    head = qoa.head;
    tail = qoa.tail;
    return *this;
}

QueueOnArray::QueueOnArray(const int size_){
    size = size_;
    array = new int[size] {0};
    tail = 0;
    head = 0;
}

QueueOnArray::~QueueOnArray(){
    if (array != nullptr){
        delete[] array;
    }
}

void QueueOnArray::push(const int a){
    if ((head % size) == tail && array[tail] != 0){
        // std::cout << "NO MORE PUSH PLZ" << std::endl;
        return; // EXCEPTION!!!!!!
    }
    if(a > 0){
        array[head] = a;
        head += 1;
        head %= size;
    }
}

void QueueOnArray::pop(){
    array[tail] = 0;
    tail += 1;
    tail %= size;
}

int QueueOnArray::top() const {
    return array[head];
}

void QueueOnArray::resize(const int newSize){
    defragment();
    if (newSize == size){
        return; // all right
    } else if (newSize > size){
        int * tempArray = new int[size];
        for (int i = 0; i < size; i++){
            tempArray[i] = array[i];
        }
        delete[] array;
        array = new int[newSize] {0};
        for (int i = 0; i < size; i++){
            array[i] = tempArray[i];
        }
        delete[] tempArray;
        size = newSize;
    } else {
        return; // EXCEPTION!!!!!!!
    }
}

std::string QueueOnArray::toString() const {
    std::string str = "";
    for (int i = 0; i < size; i++){
        str += std::to_string(array[i]);
        str += " ";
    }
    return str;
}

void QueueOnArray::defragment(){
    int * temp = new int[size];
    for (int i = 0; i < size; i++){
        temp[i] = array[(tail + i) % size];
    }

    for (int i = 0; i < size; i++){
        array[i] = temp[i];
    }
    tail = 0;

    delete[] temp;
}