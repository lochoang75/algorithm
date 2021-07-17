#ifndef COUNTING_H
#define COUNTING_H
#include <cstring>
#define MAX_ARRAY_LEN   100

int non_decreasing_counting_sort(int *head, int size) 
{
    if (head == NULL || size < 0) {
        return -1;
    }

    if (size == 1) {
        return 0;
    }

    /* we assume the maximum value of array < 100 */
    int count_array[MAX_ARRAY_LEN] = {0};
    int *temp_array = new int[size + 1];

    for (int i = 0; i < size; i++) {
        count_array[head[i]] ++;
    }

    for (int i = 1; i < MAX_ARRAY_LEN; i++) {
        count_array[i] = count_array[i] + count_array[i - 1];
    }

    for (int i = 0; i < size; i++) {
        temp_array[count_array[head[i]]] = head[i];
        count_array[head[i]] = count_array[head[i]] - 1;
    }

    memcpy(head, temp_array + 1, size * sizeof(int));
    delete[] temp_array;
    return 0;
}

int non_increasing_counting_sort(int *head, int size) 
{
    if (head == NULL || size < 0) {
        return -1;
    }

    if (size == 1) {
        return 0;
    }

    /* we assume the maximum value of array < 100 */
    int count_array[MAX_ARRAY_LEN] = {0};
    int *temp_array = new int[size + 1];

    for (int i = 0; i < size; i++) {
        count_array[head[i]] ++;
    }

    for (int i = 1; i < MAX_ARRAY_LEN; i++) {
        count_array[i] = count_array[i] + count_array[i - 1];
    }

    for (int i = 0; i < size; i++) {
        temp_array[size - count_array[head[i]]] = head[i];
        count_array[head[i]] = count_array[head[i]] - 1;
    }

    memcpy(head, temp_array, size * sizeof(int));
    delete[] temp_array;
    return 0;
}
#endif /* COUNTING_H */