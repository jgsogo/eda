
#include "sort_algorithms.h"

std::vector<float> merge(const std::vector<float>& lhs, 
                       const std::vector<float>& rhs)
{
    std::vector<float> ret;
    auto left_iterator = 0;
    auto right_iterator = 0;
 
    // Iterate the two vectors at the same time, adding the lowest element
    while (left_iterator != lhs.size() && right_iterator != rhs.size()) {
        if (lhs[left_iterator] < rhs[right_iterator]) {
            ret.push_back(lhs[left_iterator]);
            left_iterator++;
        }
        else {
            ret.push_back(rhs[right_iterator]);
            right_iterator++;
        }
    }
 
    // Add remaining elements
    for (int i=left_iterator; i<lhs.size(); i++) {
        ret.push_back(lhs[i]);
    }
    for (int i=right_iterator; i<rhs.size(); i++) {
        ret.push_back(rhs[i]);
    }
    return ret;
}

std::vector<float> merge_sort(const std::vector<float>& elements) {
    if (elements.size() <= 1) {
        return elements;
    }
    else {
        // Split the vector in two
        auto middle = elements.size()/2;
        std::vector<float> left{elements.begin(), elements.begin() + middle};
        std::vector<float> right{elements.begin() + middle, elements.end()};
 
        // Apply merge_sort to each of them
        left = merge_sort(left);
        right = merge_sort(right);
 
        // Merge those two (already) ordered vectors
        return merge(left, right);
    }
}
