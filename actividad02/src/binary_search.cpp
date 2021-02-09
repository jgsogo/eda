
#include "binary_search.h"

// This function takes a portion/slice of the given vector
std::vector<int> slice(std::vector<int> values, int begin, int end) {
    if (begin >= end) { return std::vector<int>{}; }
    return std::vector<int>(values.begin() + begin, values.begin() + end);
}

bool binary_search(std::vector<int> values, int value_to_find) {
    if (values.empty()) { return false; } // If the vector is empty, the value is not there
    int middle = values.size() / 2;
    if (value_to_find < values.at(middle)) {
        auto new_vector = slice(values, 0, middle);
        return binary_search(new_vector, value_to_find);
    }
    else if (value_to_find > values.at(middle)) {
        auto new_vector = slice(values, middle+1, values.size());
        return binary_search(new_vector, value_to_find);
    }
    else {
        return true;
    }
}
