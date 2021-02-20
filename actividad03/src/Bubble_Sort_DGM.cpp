#include <iostream>
#include <float.h>
#include <vector>
using namespace std;
#include "sort_algorithms.h"

void bubble_sort(std::vector<float>& elements) {
 for (int i=0; i<elements.size()-1; i++) {
      bool any_swap = false;
      std::cout << "Iteration " << i << std::endl;
      for (int k=0; k<elements.size()-1-i; k++) {
        std::cout << elements[k] << " > " << elements[k+1] << " ? " << (elements[k] > elements[k+1] ? "true": "false") << std::endl;
        if (elements[k] > elements[k+1]) {
          std::swap(elements[k], elements[k+1]);
          any_swap = true;
        }
      }
      if (!any_swap) { break;} // return early
    }
}
