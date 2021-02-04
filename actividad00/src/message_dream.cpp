
#include "message_dream.h"

std::string message_dream(std::string word, int level, int factor_temporal) {
    // TODO: Here it goes the algorithm
  std::string rep;
  if(level==0){return word;}
  else{
    for(auto elem:word){
      for(auto i =0; i<factor_temporal; i++){
        rep.push_back(elem);
      }
    }
    return rep;
  }

    return "Not implemented";
}
