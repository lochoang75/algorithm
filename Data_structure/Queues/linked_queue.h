#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include "queue.h"

template <class T>
class Node {
public:
    T data;
    Node *pNext;
    Node *pPrev;
    Node(): data(0), pNext(NULL), pPrev(NULL){}
    Node(T _data): data(_data), pNext(NULL), pPrev(NULL){}
    Node(const Node &_other): data(_other.data), 
                            pNext(_other.pNext), pPrev(_other.pPrev){} 
};

template <class T>
class LinkedQueue : public Queue<T> {
private:
    Node<T> *pHead;
    int count;
public:
    LinkedQueue(): Queue<T>() {
        pHead = new Node<T>();
        pHead->pNext = pHead;
        pHead->pPrev = pHead;
        this->count = 0;
    }

    LinkedQueue(int total_size): Queue<T>(total_size) {
        pHead = new Node<T>();
        pHead->pNext = pHead;
        pHead->pPrev = pHead;
        this->count = 0;
    }

    ~LinkedQueue() {
        Node<T> *temp = pHead->pNext;
        while(!isEmpty()) {
            pHead->pNext = temp->pNext;
            delete temp;
            temp = pHead->pNext;
            this->count --;
        }
        delete pHead;
        pHead = NULL;
    }

    bool isFull() {
        int total_size = Queue<T>::getQueueTotalSize();
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

    bool enQueue(T data);
    bool deQueue(T *data);
};
#endif /*LINKED_QUEUE_H */

template <class T>
bool LinkedQueue<T>::enQueue(T data) {
    Node<T> *data_node = new Node<T>(data);
    Node<T> *last_node = pHead->pPrev;
    if (!isFull() && data_node != NULL) {
        data_node->pPrev = last_node;
        last_node->pNext = data_node;
        pHead->pPrev = data_node;
        data_node->pNext = pHead;
        this->count ++;
        return 0;
    }

    return 1;
}

template <class T>
bool LinkedQueue<T>:: deQueue(T *data) {
    if (!isEmpty()) {
        Node<T> *first_node = pHead->pNext;
        (*data) = first_node->data;
        pHead->pNext = first_node->pNext;
        first_node->pNext->pPrev = pHead;
        delete first_node;
        this->count --;
        return 0;
    }
    
    return 1;
}