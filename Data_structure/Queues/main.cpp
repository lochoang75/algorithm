#include <iostream>
#include "queue.h"
#ifdef USE_ARRAY_QUEUE
#include "array_queue.h"
#endif

using namespace std;

int main(int argc, char *argv[]) {
    Queue<int> *queue = NULL;
#if USE_ARRAY_QUEUE
    ArrayQueue<int> arr_queue = ArrayQueue<int>();
    queue = &arr_queue;
#endif 

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        queue->enQueue(arr[i]);
    }

    cout << "Queue data: ";
    while(!queue->isEmpty()) {
        int data = 0;
        queue->deQueue(&data);
        cout << data << " ";
    }
    cout <<endl;
    return 0;
}