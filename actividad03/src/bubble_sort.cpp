
#include "sort_algorithms.h"
#include <iostream>
#include <vector>

void bubble_sort(std::vector<float>& elements) {
    if (elements.size() <= 1) { return; }
    for (unsigned int i=0; i<elements.size()-1; i++) {  // 'n-1' iteraciones
        for (unsigned int k=0; k<elements.size()-1; k++) {  // 'n-1' iteraciones
            // Comparar e intercambiar si el orden es incorrecto
            if (elements[k] > elements[k+1]) { // comparar valores adyacentes
                std::swap(elements[k], elements[k+1]);
            }
        }
    }
}

