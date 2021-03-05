#include "TipoDato.h"

TipoDato::TipoDato(char token)
{
    this->token = token;
}
char TipoDato::get_token() const{
    return this->token;
}
