#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
#include "queue.h"

template <class T>
class ArrayQueue : public Queue<T> {
private:
    T *data;
    int head;
    int tail;
    int size;
public:
    ArrayQueue(int _size): Queue<T>(_size), head(0), tail(0) , size(0){
        int total_size = Queue<T>::getQueueTotalSize();
        data = new T[total_size];
    }
    ArrayQueue(): Queue<T>(), head(0), tail(0), size(0) {
        int total_size = Queue<T>::getQueueTotalSize();
        data = new T[total_size];
    }

    ~ArrayQueue() {
        delete[] data;
        Queue<T>::setQueueTotalSize(0);
        this->head = 0;
        this->tail = 0;
        this->data = NULL;
    }

    bool isFull() {
        int total_size = Queue<T>::getQueueTotalSize();
        if (this->size == total_size) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

    bool enQueue(T data) {
        int total_size = Queue<T>::getQueueTotalSize();
        if (this->isFull()) {
            return false;
        } else {
            this->data[tail] = data;
            tail++;
            size++;
            if (tail == total_size) {
                tail = 0;
            }
            return true;
        }
    }

    bool deQueue(T *data) {
        int total_size = Queue<T>::getQueueTotalSize();
        if (this->isEmpty()) {
            return false;
        } else {
            (*data) = this->data[head];
            head++;
            size--;
            if (head == total_size) {
                head = 0;
            }
            return true;
        }
    }
};
#endif /*ARRAY_QUEUE_H*/