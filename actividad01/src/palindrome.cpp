#include <iostream>
#include <vector>
#include "palindrome.h"

using namespace std;

string remove_blanks(string word){ // Función que quita los espacios de un string
   string word_2;
   for(char elem: word){
       if(elem != ' '){
           word_2.push_back(elem);
       }
   }
   return word_2;
}

bool palindrome(string word){
    char primera = word.front(); char ultima = word.back();
    if(word.length() <=  1) // Caso base / trivial
    {
        return true;
    }else{
        if(primera == ultima){ // Caso general
                return palindrome(word.substr(1, word.length()-2));
        }else{
            return false;
        }
    }
}

bool is_palindrome(string word){
    string word_blanks_removed = remove_blanks(word);
    return palindrome(word_blanks_removed);
}
