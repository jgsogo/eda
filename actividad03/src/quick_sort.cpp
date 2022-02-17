
#include "sort_algorithms.h"
#include <iostream>
#include <vector>

//Función para fusionar dos listas ordenadas
int partition(std::vector<float>& elements, int left_index, int right_index)
{
    auto pivot = elements.at(left_index);
    int i = left_index, j = right_index;

    while(true) {
        while( elements.at(i) <= pivot && i < j ) ++i;
        while( elements.at(j) > pivot ) --j;
        if( i >= j ) break;
        std::swap(elements.at(i), elements.at(j));
    }
    std::swap(elements.at(left_index), elements.at(j));
    return j;
}

void quick_sort(std::vector<float>& elements, int left_index, int right_index) {
    // Caso trivial
    if (left_index >= right_index) {
        return;
    }
    else {
        // Calcule el pivote
        int pivot_index = partition(elements, left_index, right_index);

        // Aplicar quick-sort a ambos lados (el pivote está en su sitio)
        quick_sort(elements, left_index, pivot_index-1);
        quick_sort(elements, pivot_index+1, right_index);
    }
}

