
#include "sort_algorithms.h"

// A function to merge two ordered lists
int partition(std::vector<float>& elements, int left_index, int right_index)
{
    auto pivot = elements[left_index];
    int i = left_index, j = right_index;
 
    while(true) {
        while( elements[i] <= pivot && i <= j ) ++i;
        while( elements[j] > pivot ) --j;
        if( i >= j ) break;
        std::swap(elements[i], elements[j]);
    }
    std::swap(elements[left_index], elements[j]);
    return j;
}

void quick_sort(std::vector<float>& elements, int left_index, int right_index) {
    // Check for base/trivial case
    if (left_index >= right_index) {
        return;
    }
    else {
        // Compute the pivot
        int pivot_index = partition(elements, left_index, right_index);
 
        // Apply quick-sort to both sides (pivot is already in place)
        quick_sort(elements, left_index, pivot_index-1);
        quick_sort(elements, pivot_index+1, right_index);
    }
}
