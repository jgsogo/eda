#include "practica1.h"

#include <string>
#include <vector>
#include <math.h>

/****************** 
    Recursividad 
******************/

bool es_par(int num) {
    // Requires num >= 0
    if (num == 0) {
        return true;
    } else if (num == 1) {
        return false;
    } else {
        return es_par(num-2);
    }
}

int cociente(int dividendo, int divisor) {
    // Requires dividendo >=0 and divisor > 0
    if (dividendo >= divisor) {
        return 1 + cociente(dividendo-divisor, divisor);
    }
    return 0;
}

int resto(int dividendo, int divisor) {
    // Requires dividendo >=0 and divisor > 0
    if (dividendo >= divisor) {
        return resto(dividendo-divisor, divisor);
    }
    return dividendo;
}

bool es_multiplo(int num, int divisor) {
    // 'num' is multiple if resto(num, divisor) is zero, and resto is already recursive
    return resto(num, divisor) == 0;
}

int mcd(int a, int b) {
    // Euclides algorithm
    if (b == 0) {
        return a;
    }
    else {
        return mcd(b, resto(a, b));
    }
}

int sum(int N) {
    if (N == 0) {
        return 0;
    }
    else {
        return N + sum(N-1);
    }
}

int _sum_pares(int N) {
    // Always receives an even number
    if (N==0) {
        return 0;
    }
    else {
        return N + _sum_pares(N-2);
    }
}

int sum_pares(int N) {
    if (es_par(N)) {
        return _sum_pares(N);
    }
    else {
        return _sum_pares(N-1);
    }
}

int _sum_impares(int N) {
    // Always receives an odd number
    if (N<=0) {
        return 0;
    }
    else {
        return N + _sum_impares(N-2);
    }
}

int sum_impares(int N) {
    if (es_par(N)) {
        return _sum_impares(N-1);
    }
    else {
        return _sum_impares(N);
    }
}

std::string invertir(const std::string& input) {
    if (input.size() <= 1) {
        return input;
    }
    else {
        std::string ret{input.back(), 1};
        return ret + invertir(input.substr(0, input.size()-1));
    }
}

int invertir(int num) {
    if (num > 9) {
        int ud = num % 10;
        return ud*10 + invertir(num / 10);
    }
    else {
        return num;
    }
}

std::string num2binary(int num) {
    return "";
}

bool equal(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    if (lhs.empty() || rhs.empty()) {
        return lhs.empty() && rhs.empty();
    }
    else {
        auto lhs_rest = std::vector<int>{lhs.begin()+1, lhs.end()};
        auto rhs_rest = std::vector<int>{rhs.begin()+1, rhs.end()};
        return lhs.at(0) == rhs.at(0) && equal(lhs_rest, rhs_rest);
    }
}

bool _equal_array(const std::array<int, 100>& lhs, const std::array<int, 100>& rhs, int i, int j) {
    if (i>=j) {
        return true;
    }
    else {
        return (lhs[i] == rhs[i]) && _equal_array(lhs, rhs, i+1, j);
    }
}

bool _equal_matrix(const std::array<std::array<int, 100>, 100>& lhs, const std::array<std::array<int, 100>, 100>& rhs, int i, int j) {
    if (i>=j) {
        return true;
    }
    else {
        return _equal_array(lhs[i], rhs[i], 0, 100) && _equal_matrix(lhs, rhs, i+1, j);
    }
}

bool equal(const std::array<std::array<int, 100>, 100>& lhs, 
           const std::array<std::array<int, 100>, 100>& rhs) {
    return _equal_matrix(lhs, rhs, 0, 100);
}

int _sumdiv(int num, int x) {
        if(x==1) {
            return 1;
        }
        if (es_multiplo(num, x)) {
            return x + _sumdiv(num, x-1);
        }
        else {
            return _sumdiv(num, x-1);
        }
}

bool is_perfect(int num) {
    if (num == 1) {
        return false;
    }
    else {
        return _sumdiv(num, num/2) == num;
    }
}


void _bubble_sort_recursive(std::vector<int>& values, int last) {
    if (last != 0) {
        // Run one iteration of bubble-sort algorithm
        for (int k=0; k<last; k++) {
            if (values[k] > values[k+1]) { // compare adyacent values
                std::swap(values[k], values[k+1]);
            }
        }
        _bubble_sort_recursive(values, last-1);
    }
}

void bubble_sort_recursive(std::vector<int>& values) {
    /* We know that after iteration 'n' the latest 'n' elements are already ordered  */
    if (values.size() > 1) {
        _bubble_sort_recursive(values, values.size()-1);
    }
}

/****************** 
    Algorithms 
******************/

bool _greater_than(const std::string& lhs, const std::string& rhs) {
    // First check the length, if equal use lexicographic order
    if (lhs.length() == rhs.length()) {
        return lhs > rhs;
    }
    else {
        return lhs.length() > rhs.length();
    }
}

	
int partition(std::vector<std::string>& elements, int left_index, int right_index)
{
    auto pivot = elements.at(left_index);
    int i = left_index, j = right_index;
 
    while(true) {
        while( _greater_than(pivot, elements.at(i)) && i < j ) ++i;
        while( _greater_than(elements.at(j), pivot) ) --j;
        if( i >= j ) break;
        std::swap(elements.at(i), elements.at(j));
    }
    std::swap(elements.at(left_index), elements.at(j));
    return j;
}

void _quicksort_string(std::vector<std::string>& values, int left_index, int right_index) {
    if (left_index >= right_index) {
        return;
    }
    else {
        // Compute the pivot
        int pivot_index = partition(values, left_index, right_index);
 
        // Apply quick-sort to both sides (pivot is already in place)
        _quicksort_string(values, left_index, pivot_index-1);
        _quicksort_string(values, pivot_index+1, right_index);
    }
}

void quicksort_strings(std::vector<std::string>& values) {
    _quicksort_string(values, 0, values.size()-1);
}

bool _greater_than(Point lhs, Point rhs, float origin_x, float origin_y) {
    // Don't need to compute square-root as it is a constantly growing function.
    auto lhs_distance = pow(lhs.y-origin_y, 2) + pow(lhs.x-origin_x, 2);
    auto rhs_distance = pow(rhs.y-origin_y, 2) + pow(rhs.x-origin_x, 2);
    return lhs_distance > rhs_distance;
}

void sort_by_distance(std::vector<Point>& values, float origin_x, float origin_y) {
    if (values.empty()) { return; }
    // Using bubble sort
    for (int i=0; i<values.size()-1; i++) {  // 'n-1' iterations
        for (int k=0; k<values.size()-1; k++) {  // 'n-1' iterations
            if (_greater_than(values[k], values[k+1], origin_x, origin_y)) { // compare adyacent values
                std::swap(values[k], values[k+1]);
            }
        }
    }
}
