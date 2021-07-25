#include <iostream>
#include "LinkedList.h"

using namespace std;

void print_list(void *pNode) {
    int *data = (int*) pNode;
    cout << " " << *data;
}

int main(int argc, char *argv[]) {
    LinkedList<int> *list = new LinkedList<int>();
    int array[] = {1, 2, 3, 5, 4, 6, 7, 10, 8, 9};
    for (int i = 0; i < 10; i++) {
        list->list_insert(&array[i]);
    }

    cout << "Array after insert: ";
    list->list_traverse(print_list);
    cout << endl;

    cout << "Find for element = 5" << endl;
    int index = list->list_search(&array[3]);
    if (index != 0) {
        cout << "Found at: "<< index << endl;
    }

    cout << "Get element at 2" << endl;
    int element = list->list_get_index(2);
    cout << "Element get: " << element << endl;

    cout << "Remove element = 2" << endl;
    list->list_remove(&array[1]);
    cout << "List after remove: "<< endl;
    list->list_traverse(print_list);
    cout << endl;

    cout << "Insert 100 to head" << endl;
    int insert_value = 100;
    list->list_insert_head(&insert_value);
    cout << "List after insert: "<< endl;
    list->list_traverse(print_list);
    cout << endl;


    return 0;
}