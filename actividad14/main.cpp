
#include <iostream>
#include "src/PriorityQueue.h"

void copy_and_print(PriorityQueue queue) {
    std::cout << "QUEUE:" << std::endl;
    while (!queue.empty()) {
        std::cout << queue.top() << std::endl;
        queue.pop();
    }
}

int main() {
    PriorityQueue queue;
    copy_and_print(queue);

    queue.push(Avion(10, 30, false, false));
    copy_and_print(queue);

    return 0;
}
