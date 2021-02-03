#include <iostream>
#include <string>
#include <vector>
using namespace std;

string message_dream(string word, int level, int factor_temporal)
{
    if(level == 0)
    {
        return word;
    }else{
        string ret;
        for(auto elem: word)
        {
            if(elem == ' ')
            {
                ret.push_back(elem);
            }else{
                for(auto i = 0; i<factor_temporal; i++)
                {
                    ret.push_back(elem);
                }
            }
        }
        return message_dream(ret, level -1, factor_temporal);
    }
}

int main()
{
    cout<<message_dream("Hola!", 2, 2)<<"\n"; // HHHHoooollllaaaa!!!!
    cout<<message_dream("Soy Ana", 1, 3)<<"\n"; // SSSoooyyy AAAnnnaaa
}
