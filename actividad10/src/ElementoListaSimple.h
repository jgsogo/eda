
#include <memory>

#include "Client.h"

class ElementoListaSimple {
    public:
        Client client;
        std::shared_ptr<ElementoListaSimple> next = nullptr;

    public:
        ElementoListaSimple(const Client& client) : client(client) {};
};
