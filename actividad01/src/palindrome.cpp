#include <iostream>
#include <string>
#include <vector>
#include "palindrome.h"

using namespace std;

string remove_blanks(string word) {
    string word_2;
    for(auto c:word){
        if(c==' '){
            ///No necesitas hacer nada
        }else{
            word_2.push_back(c);
        }
    }
    return word_2;
}
bool is_palindrome(string word) {
    if(word.size()<2){
        return true;
    }else{
        if(word.at(0)==word.at(word.size()-1)){
             return is_palindrome(word.substr(1,word.size()-2));
        }else{
            return false;

        }

    }
}
