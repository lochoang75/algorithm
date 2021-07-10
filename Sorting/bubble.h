#ifndef BUBBLE_H
#define BUBBLE_H

template <typename T>
int non_decreasing_bubble_sort(T *head, int size)
{
    if (head == NULL || size < 0) {
        return -1;
    }

    if (size == 1) {
        return 0;
    }

    bool is_sorted = false;

    do {
        is_sorted = true;
        for (int i = 0; i < (size - 1); i++) {
            if (head[i] > head[i+1]) {
                T temp = head[i + 1];
                head[i + 1] = head[i];
                head[i] = temp;
                is_sorted = false;
            }
        }
    } while(!is_sorted);
    return 0;
}

template <typename T>
int non_increasing_bubble_sort(T *head, int size)
{
    if (head == NULL || size < 0) {
        return -1;
    }

    if (size == 1) {
        return 0;
    }

    bool is_sorted = false;

    do {
        is_sorted = true;
        for (int i = 0; i < (size - 1); i++) {
            if (head[i] < head[i+1]) {
                T temp = head[i + 1];
                head[i + 1] = head[i];
                head[i] = temp;
                is_sorted = false;
            }
        }
    } while(!is_sorted);
    return 0;

}
#endif /* BUBBLE_H */