
#include "TipoDato.h"

TipoDato::TipoDato(char token) : token(token) {}

char TipoDato::get_token() const {
    return token;
}
