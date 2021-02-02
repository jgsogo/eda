
#include "message_dream.h"

constexpr int factor_temporal = 3;

std::string message_dream(std::string word, int level) {
    if (level == 0) { return word; }
    else {
        // Every level the letters are repeated N times
        std::string ret;
        for (auto c: word) {
            int times = (c == ' ') ? 1 : factor_temporal;
            for (auto i=0; i<times; i++) {
                ret.push_back(c);
            }
        }
        // And pass the message to the next level
        return message_dream(ret, level - 1);
    }
}
