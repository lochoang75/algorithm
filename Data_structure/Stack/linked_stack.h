#ifndef LINKED_STACK_H
#define LINKED_STACK_H
#include "stack.h"

template <class T>
class Node {
public:
    T data;
    Node *pNext;
    Node(): data(0), pNext(NULL) {}
    Node(T _data): data(_data), pNext(NULL) {}
};

template <class T>
class LinkedStack: public Stack<T> {
private:
    int count;
    Node<T> *pHead;
public:
    LinkedStack(): Stack<T>() {
        this->count = 0;
        pHead = new Node<T>();
    } 

    LinkedStack(int _size): Stack<T> (_size) {
        this->count = 0;
        pHead = new Node<T>();
    }

    ~LinkedStack() {
        while(!isEmpty()) {
            Node<T> *temp = pHead->pNext;
            pHead->pNext = temp->pNext;
            delete temp;
            temp = NULL;
            this->count --;
        }
        delete pHead;
        pHead = NULL;
    }

    bool isFull() {
        int total_size = Stack<T>::getTotalSize();
        if (this->count == total_size) {
            return true;
        }

        return false;
    }

    bool isEmpty() {
        if (this->count == 0) {
            return true;
        }
        
        return false;
    }

    bool push(T data);
    bool pop(T *data);
};

template<class T>
bool LinkedStack<T>:: push(T data) {
    Node<T> *new_node = new Node<T>(data);
    if ((new_node != NULL) && (!isFull())) {
        new_node->pNext = pHead->pNext;
        pHead->pNext = new_node;
        this->count ++;
        return 0;
    }

    return 1;
}

template <class T>
bool LinkedStack<T>:: pop(T *data) {
    if (!isEmpty()) {
        Node<T> *first_data_node = pHead->pNext;
        *data = first_data_node->data;
        pHead->pNext = first_data_node->pNext;
        delete first_data_node;
        this->count--;
        return 0;
    }

    return 1;
}
#endif /* LINKED_STACK */