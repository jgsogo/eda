
#include "sort_algorithms.h"

void bubble_sort(std::vector<float> &elements) {
    if (elements.size() > 1) {
        for (int i = 0; i < elements.size() - 1; i++) { // 'n-1' iterations
            for (int k = 0; k < elements.size() - 1; k++) { // 'n-1' iterations
                if (elements[k] > elements[k + 1]) { // compare adyacent values
                    std::swap(elements[k], elements[k + 1]);
                }
            }
        }
    }
}
