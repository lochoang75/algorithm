#ifndef SELECTION_H
#define SELECTION_h
template <typename T>
int non_decreasing_selection_sort(T* head, int size)
{
    if (head == NULL) {
        return -1;
    }

    if (size == 1) {
        return 0;
    }

    for (int i = 0; i < size; i ++) {
        T tmp = head[i];
        int swap_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (tmp > head[j]) {
                tmp = head[j];
                swap_index = j;
            }
        }
        if (tmp != head[i]) {
            head[swap_index] = head[i];
            head[i] = tmp;
        }
    }

    return 0;
}

template <typename T>
int non_increasing_selection_sort(T* head, int size)
{
    if (head == NULL) {
        return -1;
    }

    if (size == 1) {
        return 0;
    }

    for (int i = 0; i < size; i ++) {
        T tmp = head[i];
        int swap_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (tmp < head[j]) {
                tmp = head[j];
                swap_index = j;
            }
        }
        if (tmp != head[i]) {
            head[swap_index] = head[i];
            head[i] = tmp;
        }
    }

    return 0;
}
#endif