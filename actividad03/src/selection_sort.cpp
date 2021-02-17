
#include "sort_algorithms.h"
#include <iostream>
#include <vector>

void selection_sort(std::vector<float>& elements) {
    for (unsigned int i=0; i<elements.size(); i++) {  // 'n' iteraciones
        //Buscar el elemento mínimo en la sección derecha (desordenada)
        int indexMin = i;
        for (unsigned int k=i+1; k<elements.size(); k++) {  // 'n-i' iteraciones
            if (elements[k] < elements[indexMin]) { // te quedas con el índice del mínimo elemento
                indexMin = k;
            }
         }
        // Intercambias el elemento actual con el mínimo
        std::swap(elements[i], elements[indexMin]);
    }
}
