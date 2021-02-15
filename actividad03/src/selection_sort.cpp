
#include "sort_algorithms.h"

void selection_sort(std::vector<float> &elements)
{
    for (int i = 0; i < elements.size(); i++) { // 'n' iterations
        // Search for the minimum element in the right (unordered) section
        int indexMin = i;
        for (int k = i + 1; k < elements.size(); k++) { // 'n-i' iterations
            if (elements[k] < elements[indexMin]) { // keep index of min element
                indexMin = k;
            }
        }
        // Swap current element with the min
        std::swap(elements[i], elements[indexMin]);
    }
}
