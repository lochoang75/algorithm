#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include "merge.h"
#include "compare.h"

using namespace std;

static void print_array(int* arr, int size) 
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

static int _merge_two_array(int *p1, int p1_size, int *p2, int p2_size, compare_result_t (*cmp) (int , int))
{
    int *arr = new int[p1_size + p2_size];
    int counter = 0;
    int idx = 0;
    for (int i = 0; i < p1_size; i++) {
        for (int j = idx; j < p2_size; j++){
            compare_result_t result = cmp(p1[i], p2[j]);
            if( result == eExpect) {
                *(arr + counter) = p1[i];
                counter++;
                break;
            } else if ( result == eEqual) {
                *(arr + counter) = p2[j];
                idx++;
                counter++;
                *(arr + counter) = p1[i];
                counter++;
                break;
            } else {
                *(arr + counter) = p2[j];
                idx++;
                counter++;
            }
        }
        if (idx == p2_size) {
            *(arr + counter) = p1[i];
            counter++;
        }
    }

    if (idx < p2_size) {
        memcpy(arr + counter, p2 + idx, sizeof(int) * (p2_size - idx));
    }

    memcpy(p1, arr, sizeof(int) *(p1_size + p2_size));
    delete[] arr;
    return 0;
}

static int* _sort(int *head, int size, compare_result_t (*cmp)(int, int))
{
    if (head == NULL) {
        return NULL;
    }

    if (size == 1) {
        return head;
    }

    if (size == 2) {
        int first = *head;
        int next = *(head + 1);
        if (cmp(first, next) == eNotExpect) {
            *head = next;
            *(head + 1) = first;
        }

        return head;
    }

    if (size > 2) {
        int* first_arr = _sort(head, (size/ 2), cmp);
        int* second_arr = NULL;
        int second_size = 0;
        if (size % 2 == 0) {
            second_size = size/2;
        } else {
            second_size = size/2 + 1;
        }
        second_arr = _sort(head + (size /2), second_size, cmp);

        _merge_two_array(first_arr, size/2, second_arr, second_size, cmp);
        return first_arr;
    }
}

int non_decreasing_merge_sort(int *head, int size)
{
    _sort(head, size, compare_smaller);
    return 0;
}

int non_increasing_merge_sort(int *head, int size)
{
    _sort(head, size, compare_bigger);
    return 0;
}