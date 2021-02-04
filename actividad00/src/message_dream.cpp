
#include "message_dream.h"
#include "math.h"

std::string message_dream(std::string word, int level, int factor_temporal) {
    
   // TODO: Here it goes the algorithm
    int veces= pow(factor_temporal,level);
    std::string rep;
    if(level==0){return word;}
    if(level!=0){
      for(auto elem:word){
        for(auto i=0; i<veces; i++){
          rep.push_back(elem);
        }
      }
      return rep;
    }

    return "Not implemented";
}
