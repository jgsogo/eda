
#include "check_braces.h"
#include "Stack.h"

bool check_braces(const std::string& braces) {
    Stack stack;
    for (auto token: braces) {
        if (token == '(' || token == '[') {
            stack.push(TipoDato{token});
        }
        else if (token == ')' || token == ']') {
            if (stack.size()) {
                char top_token = stack.top().get_token();
                stack.pop();
                if ((token == ')' && top_token != '(') || (token == ']' && top_token != '[')) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    return stack.size() == 0;
}
