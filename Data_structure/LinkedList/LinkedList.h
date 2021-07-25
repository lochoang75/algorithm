#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>

template <class T>
class Node {
public:
    T data;
    Node *pNext;
    Node *pPrev;

    Node(T _data): data(_data), pNext(NULL), pPrev(NULL){}
    Node(): data(0), pNext(NULL), pPrev(NULL) {}
};


template <class T>
class LinkedList {
private:
    Node<T> *head;
    int size;

public:
    LinkedList(): size(0) {
        head = new Node<T>();
        head->pNext = head;
        head->pPrev = head;
    }

    virtual ~LinkedList() {
        if (head != NULL) {
            head->pPrev = NULL;
            head->pNext = NULL;
            delete head;
            head = NULL;
            size = -1;
        }
    }

    bool isEmpty() {
        if (size > 0) {
            return false;
        } else {
            return true;
        }
    }

    int list_get_size() {
        return this->size;
    }

    int list_search (T *key);
    int list_remove(T *key);
    int list_remove(int index);
    int list_remove_all();
    int list_insert(T *key);
    int list_insert(T *key, int index);
    int list_insert_head(T *key);
    T list_get_index(int index);
    void list_traverse(void (*action)(void*));
};

template <class T>
int LinkedList<T>:: list_search(T *key) {
    Node<T>* temp = head->pNext;
    int index = 0;
    while(temp != head) {
        if (*key == temp->data){
            return index;
        }
        index ++;
        temp = temp->pNext;
    }
    return 0;
}

template <class T> 
int LinkedList<T>:: list_remove(T *key) {
    Node<T> *temp = head->pNext;
    while(temp != head) {
        if (temp->data == *key) {
            Node<T> *prev = temp->pPrev;
            Node<T> *next = temp->pNext;
            prev->pNext = next;
            next->pPrev = prev;
            delete temp;
            temp = next;
            size--;
        }
        temp = temp->pNext;
    }
    
    return 0;
}

template <class T>
int LinkedList<T>:: list_remove(int index) {
    if (size < index) {
        return -1;
    }

    int counter = 0;
    Node<T> *temp = head;
    if (index < (size/2)) {
        counter = size;
        while(counter > index) {
            temp = temp->pPrev;
            counter --;
        }
    } else {
        while(index > 0) {
            temp = temp->pNext;
            index --;
        }
    }

    Node<T> *prev = temp->pPrev;
    Node<T> *next = temp->pNext;
    prev->pNext = next;
    next->pPrev = prev;
    delete temp;
    size --;
    return 0;
}

template <class T>
int LinkedList<T>:: list_remove_all() {
    while(!isEmpty()) {
        Node<T> *temp = head->pNext;
        Node<T> *next = temp->pNext;
        head = temp->pNext;
        next->pPrev = head;
        delete temp;
        size --;
    }
    
    return 0;
}

template <class T>
int LinkedList<T>::list_insert(T *key) {
    Node<T> *last_node = head->pPrev;
    Node<T> *temp = new Node<T>(*key);
    last_node->pNext = temp;
    temp->pPrev = last_node;
    temp->pNext = head;
    head->pPrev = temp;
    size++;
    return 0;
}

template <class T>
int LinkedList<T>:: list_insert(T *key, int index) {
    if (size < index) {
        return -1;
    }

    int counter = 0;
    Node<T> *temp = head;
    if (index < (size/2)) {
        counter = size;
        while(counter > index) {
            temp = temp->pPrev;
            counter --;
        }
    } else {
        while(index > 0) {
            temp = temp->pNext;
            index --;
        }
    }

    Node<T> *prev = temp->pPrev;
    Node<T> *node = new Node<T>(*key);
    prev->pNext = node;
    temp->pPrev = node;
    node->pPrev = prev;
    node->pNext = temp;
    size++;
    return 0;
}

template <class T>
int LinkedList<T>::list_insert_head(T *key) {
    Node<T> *node = new Node<T>(*key);
    node->pNext = head->pNext;
    node->pPrev = head;
    head->pNext = node;
    size++;
    return 0; 
}

template <class T>
T LinkedList<T>:: list_get_index(int index) {
    if (size < index) {
        return -1;
    }

    int counter = 0;
    Node<T> *temp = head;
    if (index < (size/2)) {
        counter = size;
        while(counter > index) {
            temp = temp->pPrev;
            counter --;
        }
    } else {
        while(index > 0) {
            temp = temp->pNext;
            index --;
        }
    }

    return temp;
}

template <class T>
void LinkedList<T>:: list_traverse(void (*action)(void*)) {
    Node<T> *temp = head->pNext;
    while(temp != head) {
        action((void*)temp);
        temp=temp->pNext;
    }
}
#endif /*LINKED_LIST */
