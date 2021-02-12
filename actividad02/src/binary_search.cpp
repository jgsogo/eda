
#include "binary_search.h"
#include <iostream>
#include <vector>

//te muestra por pantalla el vector
void print_vector(std::vector<int> values) {
    for (auto v: values) {
        std::cout << v << ", ";
    }
    std::cout << std::endl;
}

//Para obtener la mitad del vector que quiero
std::vector<int> slice(std::vector<int> values, int begin, int end) {
    if (begin >= end) { return std::vector<int>{}; }
    return std::vector<int>(values.begin() + begin, values.begin() + end);
}

bool binary_search(std::vector<int> values, int value_to_find) {
    //Muestra el vector como queda en cada iteración
    print_vector(values);
    //caso trivial: valor no encontrado
    if (values.empty()) { return false; }
    //variable que contiene el valor medio
    int middle = values.size() / 2;
    //si el valor es menor al valor medio cojo la primera mitad del vector
    if (value_to_find < values.at(middle)) {
        return binary_search(slice(values,0,middle), value_to_find);
    }
    //si el valor es mayor al valor medio cojo la segunda mitad del vector
    else if (value_to_find > values.at(middle)) {
        return binary_search(slice(values,middle+1,values.size()), value_to_find);
    }
    //caso: value_to_find == values.at(middle)
    else {
        return true;
    }
}
