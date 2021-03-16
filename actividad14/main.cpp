
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

    queue.push(Avion(11, 30, false, false));
    queue.push(Avion(11, 30, true, false));
    queue.push(Avion(11, 30, true, true));
    queue.push(Avion(11, 20, false, true));
    queue.push(Avion(11, 10, false, false));
    queue.push(Avion(13, 10, false, false));
    queue.push(Avion(10, 10, true, false));
    copy_and_print(queue);

    return 0;
}
