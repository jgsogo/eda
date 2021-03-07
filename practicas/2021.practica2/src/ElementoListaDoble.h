#pragma once

#include <memory>
#include "Persona.h"

class ElementListaDoble {
    public:
        // Members
        Persona dato;
        std::shared_ptr<ElementListaDoble> next = nullptr;
        std::shared_ptr<ElementListaDoble> prev = nullptr;
    public:
        // Constructor 
        ElementListaDoble(const Persona& dato_);
};
