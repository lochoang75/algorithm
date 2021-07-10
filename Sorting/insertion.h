#ifndef INSERTION_H
#define INSERTION_H
#include <iostream>

template <typename T>
int non_decreasing_insertion_sort(T *head, int size) 
{
    if (head == NULL || size < 0) {
        return -1;
    }

    if (size < 2) {
        return 0;
    }

    for (int j = 1; j < size; j++) {
        T key = head[j];
        int i = j - 1;
        while (i >= 0) {
            if (head[i] > key) {
                head[i + 1] = head[i];
                i--;
            } else {
                break;
            } 
        }
        head[i + 1] = key;
    } 
    return 0;
}

template <typename T>
int non_increasing_insertion_sort(T *head, int size)
{
    if (head == NULL || size < 0) {
        return -1;
    }

    if (size < 2) {
        return 0;
    }

    for (int j = 1; j < size; j++) {
        T key = head[j];
        int i = j - 1;
        while (i >= 0) {
            if (head[i] < key) {
                head[i + 1] = head[i];
                i--;
            } else {
                break;
            } 
        }
        head[i + 1] = key;
    } 
    return 0;

}
#endif /* INSERTION_H */