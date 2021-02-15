
#include "sort_algorithms.h"

void quick_sort(std::vector<float>& elements, int left_index, int right_index) {
    std::sort(elements.begin() + left_index, elements.begin() + right_index + 1);
}
