#ifndef STACK_H
#define STACK_H
template <class T>
class Stack {
private:
    int total_size;
public:
    Stack(int _size): total_size(_size) {};
    Stack(): total_size(100) {};
    virtual ~Stack(){};
    int getTotalSize() {
        return this->total_size;
    }

    void setTotalSize(int size) {
        this->total_size = size;
    }

    virtual bool push(T data){ return true;};
    virtual bool pop(T *data){ return true;};
    virtual bool isFull(){ return true;};
    virtual bool isEmpty(){ return true;};
};
#endif /*STACK_H*/