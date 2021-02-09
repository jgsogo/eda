
#include "message_dream.h"

std::string message_dream(std::string word, int level, int factor_temporal) {
    /* Solución recursiva */
    if (level == 0) {return word;}
    else {
        std::string ret;
        for (auto c: word) {
            if (c == ' ') {ret.push_back(c);}
            else {
                for (int j=0; j<factor_temporal; j++) {
                    ret.push_back(c);
                }    
            }
        }
        return message_dream(ret, level-1, factor_temporal);
    }
}