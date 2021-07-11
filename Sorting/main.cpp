#include <iostream>

using namespace std;

#ifdef USE_INSERTION_SORT
#include "insertion.h"
#endif
#ifdef USE_BUBBLE_SORT
#include "bubble.h"
#endif

#ifdef USE_SELECTION_SORT
#include "selection.h"
#endif

#ifdef USE_MERGE_SORT
#include "merge.h"
#endif

#ifdef USE_QUICK_SORT
#include "quick.h"
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

#ifdef USE_SELECTION_SORT
    cout << "************ USE BUBBLE ****************" << endl;
    return non_decreasing_selection_sort(arr, size);
#endif /* USE_SELECTION_SORT */

#ifdef USE_MERGE_SORT
    cout << "************ USE MERGE *****************" << endl;
    return non_decreasing_merge_sort(arr, size);
#endif /* USE_MERGE_SORT */

#ifdef USE_QUICK_SORT
    cout << "************ USE QUICK *****************" << endl;
    return non_decreasing_quick_sort(arr, size);
#endif /* USE_QUICK_SORT */
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

#ifdef USE_SELECTION_SORT
    cout << "************ USE BUBBLE ****************" << endl;
    return non_increasing_selection_sort(arr, size);
#endif /* USE_SELECTION_SORT */

#ifdef USE_MERGE_SORT
    cout << "************ USE_MERGE *****************" << endl;
    return non_increasing_merge_sort(arr, size);
#endif /* USE_MERGE_SORT */

#ifdef USE_QUICK_SORT
    cout << "************ USE QUICK *****************" << endl;
    return non_increasing_quick_sort(arr, size);
#endif /* USE_QUICK_SORT */
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

    int arr_2[] = {10, 20, 30, 20, 10, 50};
    size = sizeof(arr_2) / sizeof(int);
    cout << "TEST 2" << endl;
    cout << "Array before sort: ";
    print_array(arr_2, size);
    non_decreasing_sort(arr_2, size);
    cout << "Array after sort: ";
    print_array(arr_2, size);

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