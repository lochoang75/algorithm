#include <iostream>

using namespace std;

#ifdef USE_INSERTION_SORT
#include "insertion.h"
#endif
#ifdef USE_BUBBLE_SORT
#include "bubble.h"
#endif

void print_array(int* arr, int size) 
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int non_decreasing_sort(int *arr, int size)
{
#ifdef USE_INSERTION_SORT
    cout << "************ USE INSERTION ****************" << endl;
    return non_decreasing_insertion_sort(arr, size);
#endif /* USE_INSERTION_SORT */

#ifdef USE_BUBBLE_SORT
    cout << "************ USE BUBBLE ****************" << endl;
    return non_decreasing_bubble_sort(arr, size);
#endif /* USE_BUBBLE_SORT */
}

int non_increasing_sort(int *arr, int size)
{
#ifdef USE_INSERTION_SORT
    cout << "************ USE INSERTION ****************" << endl;
    return non_increasing_insertion_sort(arr, size);
#endif /* USE_INSERTION_SORT */

#ifdef USE_BUBBLE_SORT
    cout << "************ USE BUBBLE ****************" << endl;
    return non_increasing_bubble_sort(arr, size);
#endif /* USE_BUBBLE_SORT */
}

void run_all_test()
{
    int arr[] = {31, 41, 59, 26, 41, 58};
    int size = sizeof(arr) / sizeof(int);
    cout << "TEST 1" << endl;
    cout << "Array before sort: ";
    print_array(arr, size);
    non_decreasing_sort(arr, size);
    cout << "Array after sort: ";
    print_array(arr, size);
}

int main(int argc, char * argv[]) {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int size = sizeof(arr) / sizeof(int);
    cout << "Array before sort: ";
    print_array(arr, size);
    int ret = non_decreasing_sort(arr, size);
    if (ret != 0) {
        cout << "Error while sort the array" << endl;
    } else {
        cout << "Array after sort: ";
        print_array(arr, size);
    }
    int arr_2[] = {5, 2, 4, 6, 1, 3};
    ret = non_increasing_sort(arr_2, size);
    cout << "Non increasing sort: ";
    if (ret != 0) {
        cout << "Error while sort the array" << endl;
    } else {
        print_array(arr_2, size);
    }
    run_all_test();
    return 0;
}