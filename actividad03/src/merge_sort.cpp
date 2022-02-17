
#include "sort_algorithms.h"
#include <iostream>
#include <vector>

//función para fusionar dos listas ordenadas
std::vector<float> merge(const std::vector<float>& lhs,
                       const std::vector<float>& rhs)
{
    std::vector<float> ret;
    auto left_iterator = 0;
    auto right_iterator = 0;

    //Iteras los dos vectores al mismo tiempo, añadiendo el elemento más pequeño
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

    //Añadir elementos restantes
    for (int i=left_iterator; i<lhs.size(); i++) {
        ret.push_back(lhs[i]);
    }
    for (int i=right_iterator; i<rhs.size(); i++) {
        ret.push_back(rhs[i]);
    }
    return ret;
}

std::vector<float> merge_sort(const std::vector<float>& elements) {
    // Caso trivial
    if (elements.size() <= 1) {
        return elements;
    }
    else {
        // Dividir el vector en dos
        auto middle = elements.size()/2;
        std::vector<float> left{elements.begin(), elements.begin() + middle};
        std::vector<float> right{elements.begin() + middle, elements.end()};

        // Aplicar el algoritmo merge_sort a cada vector
        left = merge_sort(left);
        right = merge_sort(right);

        // Fusiona los dos vectores (left, right) ya ordenados
        return merge(left, right);
    }
}

