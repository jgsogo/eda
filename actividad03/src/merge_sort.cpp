
#include "sort_algorithms.h"

std::vector<float> merge_sort(const std::vector<float>& elements) {
    std::vector<float> ret{elements.begin(), elements.end()};
    std::sort(ret.begin(), ret.end());
    return ret;
}
