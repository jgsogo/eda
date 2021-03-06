#include <string>
#include <vector>

bool es_par(int num);

int cociente(int dividendo, int divisor);

int resto(int dividendo, int divisor);

bool es_multiplo(int num, int divisor);

int mcd(int a, int b);

int sum(int N);

int sum_pares(int N);

int sum_impares(int N);

std::string invertir(const std::string& input);

int invertir(int num);

std::string num2binary(int num);

bool equal(const std::vector<int>& lhs, const std::vector<int>& rhs);

bool equal(const std::array<std::array<int, 100>, 100>& lhs, 
           const std::array<std::array<int, 100>, 100>& rhs);

bool is_perfect(int num);

void bubble_sort_recursive(std::vector<int>& values);

void quicksort_strings(std::vector<std::string>& values);

struct Point { float x, y; };
void sort_by_distance(std::vector<Point>& values, float origin_x, float origin_y);
