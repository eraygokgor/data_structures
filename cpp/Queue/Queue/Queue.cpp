#include <iostream>
#include "Queue.h"

int main() {
    // Some tests for queue adt
    
    Queue<int> q;
    for (int i=0; i < 10; i++){
        q.enqueue(i);
    }
    std::cout << "Printing q:" << std::endl;
    while (!q.isEmpty()) {
        int value;
        q.dequeue(value);
        std::cout << value << std::endl;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
