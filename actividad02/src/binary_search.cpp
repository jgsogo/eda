#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <memory>
#include <functional>
using namespace std;

#include "binary_search.h"

std::vector<int> slice(std::vector<int> values, int begin, int end) {
    if (begin >= end) { return std::vector<int>{}; }
    return std::vector<int>(values.begin() + begin, values.begin() + end);
}
bool binary_search(std::vector<int> values, int value_to_find) {
    if (values.empty()) { return false; }
    // TODO: Implement algorithm here
    int middle = values.size() / 2; 
    if(value_to_find < values.at(middle)){
        auto new_vec = slice(values,0,middle);
        return binary_search(new_vec,value_to_find);
    }else if(value_to_find > values.at(middle)){
        auto new_vec = slice(values,middle+ 1,values.size());
        return binary_search(new_vec, value_to_find);
    }else {
        return true;
    }
}
