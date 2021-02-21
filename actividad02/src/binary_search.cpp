
#include "binary_search.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> slice(vector<int> values, int begin, int end){
    if(begin >= end){
        return vector<int>{};
    }else{
        return vector<int>(values.begin() + begin, values.begin() + end);
    }
}

bool binary_search(vector<int> values, int value_to_find){
    print_vector(values);
    if(values.empty()){
        return false;
    }
    int middle = values.size()/2;
    if(value_to_find < values.at(middle)){
        auto new_vector = slice(values, 0, middle);
        return binary_search(new_vector, value_to_find);
    }
    else if (value_to_find > values.at(middle)) {
        auto new_vector = slice(values, middle + 1, values.size());
        return binary_search(new_vector, value_to_find);
    }else{
        return true;
    }

}
