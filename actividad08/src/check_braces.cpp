#include "check_braces.h"
#include "Stack.h"

bool check_braces(const std::string& braces) {
    Stack checker;

    for(unsigned int i = 0; i < braces.size(); i++){
        char token = braces.at(i);
        if(token == '(' || token == '['){
            checker.push(token);
        }else if(token == ')' || token == ']'){
            if(checker.size() != 0){
                auto last = checker.top();
                checker.pop();
                if( (token == ')' && last.get_token() != '(') ||
                    (token == ']' && last.get_token() != '[')){
                    return false;
                }
            }else{
                return false;
            }

        }
    }
    return (checker.size() == 0)?true:false;

}

