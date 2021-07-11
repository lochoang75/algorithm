#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <stdio.h>
#include "quick.h"
#include "compare.h"

using namespace std;

static void print_array(int* arr, int size) 
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* We will select first element as pivot */
static int* _sort(int *head, int size, compare_result_t (*cmp) (int, int))
{
    if (head == NULL) {
        return NULL;
    }

    if (size == 1) {
        return head;
    }

    int *temp_array = new int[size];
    int pivot = *head;
    int left_counter = 0;
    int right_counter = size - 1;
    // index 0 is pivot
    for (int i = 1; i < size; i++) {
        if (cmp(pivot, *(head + i)) == eExpect) {
            *(temp_array + right_counter) = head[i];
            right_counter --;
        } else {
            *(temp_array + left_counter) = head[i];
            left_counter++;
        }
    }

    if (left_counter != right_counter) {
        printf("Logic:error left: %d right: %d \n", left_counter, right_counter);
    } else {
        temp_array[left_counter] = pivot;
    }

    if (left_counter > 0) {
        _sort(temp_array, left_counter, cmp);
    }

    if (right_counter < (size -1)) {
        _sort(temp_array + left_counter + 1, size - left_counter - 1, cmp);
    }

    memcpy(head, temp_array, size* sizeof(int));
    delete[] temp_array;
}

int non_decreasing_quick_sort(int *head, int size)
{
    _sort(head, size, compare_smaller);
}

int non_increasing_quick_sort(int *head, int size)
{
    _sort(head, size, compare_bigger);
}

