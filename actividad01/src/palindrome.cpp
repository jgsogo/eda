
#include "palindrome.h"

bool is_palindrome(std::string word) {
    if (word.size() <= 1) { return true; }
    else {
        if (word.at(0) != word.at(word.size()-1)) { return false; }
        else {
            return is_palindrome(word.substr(1, word.size() - 2));
        }
    }
    return false;
}
