#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue {
private:
    int total_size;
public:
    Queue(int _size): total_size(_size) {}
    Queue(): total_size(100) {}
    virtual ~Queue(){}
    void setQueueTotalSize(int _size) {
        this->total_size = _size;
    }
    int getQueueTotalSize() {
        return this->total_size;
    }
    virtual bool isFull() {return true;}
    virtual bool isEmpty() {return true;}
    virtual bool enQueue(T data) {return true;}
    virtual bool deQueue(T *data) {return true;}
};
#endif /*QUEUE_H */