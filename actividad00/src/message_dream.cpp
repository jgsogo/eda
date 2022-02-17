#include "message_dream.h"
#include <iostream>
#include <string>

std::string message_dream(std::string word, int level, int factor_temporal) {
    if (level == 0) {
        return word;
    }else {
        std::string new_word;
        for (auto w: word) {
            if( w == ' '){
                new_word.push_back(w);
            }else{
                for (auto i=0; i<factor_temporal; i++) {
                    new_word.push_back(w);
                }
            }
        }
        return message_dream(new_word, level - 1, factor_temporal);
    }
}
