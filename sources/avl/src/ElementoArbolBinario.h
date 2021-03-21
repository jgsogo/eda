#pragma once

#include <memory>

using TipoDato = int;

class ElementoArbolBinario {
    public:
        // Members
        TipoDato dato;
        std::shared_ptr<ElementoArbolBinario> left = nullptr;
        std::shared_ptr<ElementoArbolBinario> right = nullptr;
    public:
        // Constructor 
        ElementoArbolBinario(const TipoDato& dato_) : dato{dato_} {};
};
