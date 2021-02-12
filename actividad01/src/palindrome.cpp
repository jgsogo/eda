
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
    std::string word_without_blanks = remove_blanks(word);
    if(word_without_blanks.length() <= 1){return true;}
    if(word_without_blanks.at(0) == word_without_blanks.at(word_without_blanks.length()-1)){
        return is_palindrome(word_without_blanks.substr(1,word_without_blanks.length()-2));
    }
    return false;
}
