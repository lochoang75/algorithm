#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H 
#include "stack.h"
template <class T>
class ArrayStack: public Stack<T> {
private:
    int size;
    T *data;

    int _stack_array_allocate() {
        int total_size = Stack<T>::getTotalSize();
        data = new T[total_size];
        if (data != NULL) {
            return 1;
        }
        return 0;
    }

    int _stack_array_deallocate() {
        delete[] data;
        data = NULL;
        return 0;
    }

public:
    ArrayStack(int _size): Stack<T>(_size), size(0), data(NULL) {
        _stack_array_allocate();
    }

    ArrayStack(): size(0), Stack<T>(100), data(NULL) {
        _stack_array_allocate();
    }
    
    virtual ~ArrayStack() {
        this->size = 0;
        Stack<T>::setTotalSize(0);
        _stack_array_deallocate();
    }

    bool isFull() {
        int total_size = Stack<T>::getTotalSize();
        if (this->size == total_size) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (this->size == 0) {
            return true;
        }
        return false;
    }

    bool push(T data) {
        if (this->isFull()) {
            return false;
        }

        this->data[this->size] = data;
        this->size++;
        return true;
    }

    bool pop(T *data) {
        if (this->isEmpty()) {
            return false;
        }

        (*data) = this->data[this->size - 1];
        this->size--;
        return true;
    }
};
#endif /*ARRAY_STACK_H */