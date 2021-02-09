
#include "palindrome.h"

#include <algorithm>


bool _is_palindrome(std::string word) {
    if (word.size() <= 1) { return true; }
    else {
        if (word.at(0) != word.at(word.size()-1)) { return false; }
        else {
            return is_palindrome(word.substr(1, word.size() - 2));
        }
    }
    return false;
}

bool is_palindrome(std::string word) {
    // Remove the blanks and then delegate work to the actual algorithm
    word.erase(std::remove_if(word.begin(), word.end(), std::isspace), word.end());
    return _is_palindrome(word);
}
