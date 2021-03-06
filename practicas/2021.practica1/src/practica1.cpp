#include "practica1.h"

#include <string>
#include <vector>

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

bool is_perfect(int num) {
    return false;
}

void bubble_sort_recursive(std::vector<int>& values) {

}

/****************** 
    Algorithms 
******************/

void quicksort_strings(std::vector<std::string>& values) {

}

void sort_by_distance(std::vector<Point>& values, float origin_x, float origin_y) {

}
