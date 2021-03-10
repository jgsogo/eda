#include "practica1.h"

#include <string>
#include <vector>
#include <math.h>

/******************
    Recursividad
******************/

//Paridad de un número mediante restas (recursividad simple).
bool es_par(int num) {
   if(num == 0){return true;}
   if(num == 1){return false;}
   return es_par(num-2);
}

//Calcular el cociente de una división entera
int cociente(int dividendo, int divisor) {
   if(divisor > dividendo){return 0;}
   return cociente(dividendo-divisor, divisor) +1;
}

//Calcular el resto de una división entera
int resto(int dividendo, int divisor){
    if(dividendo<divisor){return dividendo;}
    return resto(dividendo-divisor,divisor);
}

//implementar una función que devuelva si un número es
//o no divisible por otro número
bool es_multiplo(int num, int divisor){
    if(resto(num,divisor) == 0 ){return true;}
    return false;
}

//Implementar una función que calcule el máximo común divisor aplicando
//el algoritmo de Euclides. Justifica y razona su orden de complejidad
int mcd(int a, int b){
    if(b==0){return a;}
    return mcd(b,a%b);
}

//Sumatorio de los números del 1 al N (incluido)
int sum(int N){
    if(N==0){return 0;}
    if(N==1){return 1;}
    return sum(N-1) + N;
}

//Sumatorio de los números pares del 1 al N (incluido)
int sum_pares(int N){
    if(N==0){return 0;}
    if(N==1){return 0;}
    if(es_par(N)){return N + sum_pares(N-1);}
    return sum_pares(N-1);
}

//Sumatorio de los números impares del 1 al N (incluido)
int sum_impares(int N){
    if(N==0){return 0;}
    if(N==1){return 1;}
    if(!es_par(N)){return N + sum_impares(N-1);}
    return sum_impares(N-1);
}

//Implementar una función que invierta un string que recibe como argumento
std::string invertir(const std::string& input){
    if(input.length() == 0){ return input;}
    return invertir(input.substr(1)) + input.front();
}

//Implementar una función que invierta los dígitos de un número entero
int invertir(int num){
    //la función atoi analiza la cadena
    //e interpreta su contenido como un número entero
    return atoi(invertir(std::to_string(num)).c_str());
}

//Representa en binario un número entero sin signo
std::string num2binary(int num){
    if(num < 2){return std::to_string(num);}
    return  num2binary(num/2) + std::to_string(num%2);
}

//Implementar una función que indique si dos vectores pasados
//como argumento son iguales
bool equal( const std::vector<int>& lhs, const std::vector<int>& rhs){
    if(lhs.size() == 0 && rhs.size() == 0){return true;}
    if(lhs.size() != rhs.size()){return false;}
    if(lhs.back() == rhs.back()){
        std::vector<int> auxlhs = lhs;
        std::vector<int> auxrhs = rhs;
        auxlhs.pop_back();
        auxrhs.pop_back();
        return equal(auxlhs,auxrhs);
    }
    return false;
}

//Implementar una función que indique si dos matrices pasadas
//como argumento son iguales
bool auxiliar_equal(const std::array<std::array<int,100>,100>& lhs,
                   const std::array<std::array<int,100>,100>& rhs, int auxsize){
    bool equal = true;
    if(auxsize == -1){ return true;}
    else{
        for(int j=0; j<100;j++){
            if(lhs[auxsize][j] != rhs[auxsize][j])
                equal = false;
        }
        if(equal == true){return auxiliar_equal(lhs,rhs,auxsize-1);}
        return false;
    }
}

bool equal(const std::array<std::array<int, 100>, 100>& lhs,
           const std::array<std::array<int, 100>, 100>& rhs){
    return auxiliar_equal(lhs,rhs, 100 - 1);
}

//Función que determine si un número es perfecto
int sumaDivisores(int num, int num1){
    if(num1==0){return 0;}
    if(num1==1){return 1;}
    if(num%num1 == 0){return num1 + sumaDivisores(num,num1-1);}
    return sumaDivisores(num,num1-1);
}

bool is_perfect(int num){
     int result = sumaDivisores(num,num-1);
     return result == num?true:false;
}


//Implementar el método de ordenación de la burbuja de manera recursiva
void auxiliar_bubble_sort_recursive(std::vector<int>& values, int auxsize){
    if(auxsize <= 1){return;}
    for(int i=0; i<auxsize-1;i++){
        if(values[i]>values[i+1]){
            std::swap(values[i], values[i+1]);
        }
    }
    auxiliar_bubble_sort_recursive(values,auxsize-1);
}

void bubble_sort_recursive(std::vector<int>& values){
    auxiliar_bubble_sort_recursive(values,values.size());
}

/******************
    Algorithms
******************/

//Utilizar el algoritmo Quicksort para ordenar un vector de cadenas
//según la longitud de cada palabra (las más cortas delante).
//A igual longitud, utilizar el orden lexicográfico.
int partition(std::vector<std::string>& values, int left_index, int right_index)
{
    auto pivot = values.at(left_index);
    int i = left_index, j = right_index;

    while(true) {
        while( values.at(i).length() <= pivot.length() && i < j) ++i;
        while( values.at(j).length() > pivot.length()) --j;
        if( i >= j ) break;
        std::swap(values.at(i), values.at(j));
    }

    if(values.at(left_index).length() == values.at(j).length()){
        if(values.at(left_index) > values.at(j)){
            std::swap(values.at(left_index), values.at(j));
        }
    }else{
        std::swap(values.at(left_index), values.at(j));
    }
    return j;
}

void auxiliar_quicksort_strings(std::vector<std::string>& values, int left_index, int right_index) {
    // Caso base
    if (left_index >= right_index) {
        return;
    }
    else {
        // Calcular el pivote
        int pivot_index = partition(values, left_index, right_index);

        // Aplicar quick-sort a ambos lados (el pivote ya está en su lugar)
        auxiliar_quicksort_strings(values, left_index, pivot_index-1);
        auxiliar_quicksort_strings(values, pivot_index+1, right_index);
    }
}

void quicksort_strings(std::vector<std::string>& values){
    auxiliar_quicksort_strings(values, 0, values.size()-1);
}

//Dado un vector de estructuras, donde cada estructura almacena
//las coordenadas x e y de un punto, implementar una función que
//ordene los elementos según su distancia a otro punto dado como argumento
float distancia(Point punto, float x2, float y2){
    return sqrt(((x2-punto.x)*(x2-punto.x)) + ((y2-punto.y)*(y2-punto.y)));
}

void sort_by_distance(std::vector<Point>& values, float origin_x, float origin_y){
    for (unsigned int i=0; i<values.size(); i++) {  // 'n' iteracciones
        // Buscar el mínimo elemento en la sección (desordenada) derecha
        int indexMin = i;
        for (unsigned int k=i+1; k<values.size(); k++) {  // 'n-i' iteracciones
            float distanciaK = distancia(values[k],origin_x,origin_y);
            float distanciaIndexMin = distancia(values[indexMin],origin_x,origin_y);
            if (distanciaK < distanciaIndexMin) { // mantener el índice del elemento mínimo
                indexMin = k;
            }
         }
        // Intercambiar elemento actual con el mínimo
        std::swap(values[i], values[indexMin]);
    }
}
