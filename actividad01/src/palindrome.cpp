
#include "palindrome.h"
#include <iostream>
#include <vector>

std::string remove_blanks(std::string word) {
    std::string new_word;
    for(auto v: word){
        if(v != ' '){
            new_word.push_back(v);
        }
    }
    return new_word;
}

// Recursion: 'word' will be a palindrome if 'word[1, len-1]' is a palindrome
bool is_palindrome(std::string word) {
    if(word.length() <= 1){return true;}
    if(word.at(0) == word.at(word.length()-1)){
        return is_palindrome(word.substr(1,word.length()-2));
    }
    return false;
}

bool is_palindrome(std::string word) {
    std::string word_without_blanks = remove_blanks(word);
    return _is_palindrome(word_without_blanks);
}
