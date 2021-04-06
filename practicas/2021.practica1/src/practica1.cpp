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
        std::string ret{input.back()};
        return ret + invertir(input.substr(0, input.size()-1));
    }
}

int invertir(int num) {
    int cociente = num / 10;
    int resto = num % 10;
    if (cociente != 0) {
        // I need to multiply 'resto' to the 10^i where 'i' is the length of 'num'
        int factor = pow(10, int(log10(num)));
        return resto*factor + invertir(cociente);
    }
    else {
        return resto;
    }
}

std::string num2binary(int num) {
    if (num == 0) {
        return "0";
    }
    else if (num == 1) {
        return "1";
    }
    else {
        std::string here = (num % 2 == 0) ? "0" : "1";
        return num2binary(num / 2) + here;
    }
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
        return (lhs.at(i) == rhs.at(i)) && _equal_array(lhs, rhs, i+1, j);
    }
}

bool _equal_matrix(const std::array<std::array<int, 100>, 100>& lhs, const std::array<std::array<int, 100>, 100>& rhs, int i, int j) {
    if (i>=j) {
        return true;
    }
    else {
        return _equal_array(lhs.at(i), rhs.at(i), 0, 100) && _equal_matrix(lhs, rhs, i+1, j);
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

bool _gt_than(const std::string& lhs, const std::string& rhs) {
    // Greater than: first check the length, if equal use lexicographic order
    if (lhs.length() == rhs.length()) {
        return lhs > rhs;
    }
    else {
        return lhs.length() > rhs.length();
    }
}

bool _lte_than(const std::string& lhs, const std::string& rhs) {
    // Less than or equal: first check the length, if equal use lexicographic order
    if (lhs == rhs) {
        return true;
    }
    else {
        return _gt_than(rhs, lhs);
    }
}

	
int partition(std::vector<std::string>& elements, int left_index, int right_index)
{
    auto pivot = elements.at(left_index);
    int i = left_index, j = right_index;
 
    while(true) {
        while( _lte_than(elements.at(i), pivot) && i < j ) ++i;
        while( _gt_than(elements.at(j), pivot) ) --j;
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
