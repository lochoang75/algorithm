#include <iostream>
#include "stack.h"
#ifdef USE_ARRAY_STACK
#include "array_stack.h"
#endif /* USE_ARRAY_STACK */

using namespace std;

int main(int argc, char *argv[]) {
    Stack<int> *stack = NULL;
#ifdef USE_ARRAY_STACK
    ArrayStack<int> array_stack = ArrayStack<int>();
    stack = &array_stack;
#endif /*USE ARRAY STACK */

    int temp_arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++) {
        stack->push(temp_arr[i]);
    }

    cout << "Data pop: ";
    while(!stack->isEmpty()) {
        int data = 0;
        if (stack->pop(&data)) {
            cout << data << " ";
        }
    }
    cout << endl;
    return 0;
}