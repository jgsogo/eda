#pragma once

#include <vector>
#include <memory>
#include "TipoDato.h"


class ElementoArbol {
    public:
        // Members
        TipoDato dato;
        std::vector<std::shared_ptr<ElementoArbol>> children;
    public:
        // Constructor 
        ElementoArbol(const TipoDato& dato_) : dato{dato_} {};
};
