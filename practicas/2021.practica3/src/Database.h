#include <memory>
#include <functional>

#include "Empleado.h"

class ElementoArbolBinario {
    public:
        // Members
        Empleado dato;
        std::shared_ptr<ElementoArbolBinario> left = nullptr;
        std::shared_ptr<ElementoArbolBinario> right = nullptr;
    public:
        // Constructor 
        ElementoArbolBinario(const Empleado& dato_) : dato{dato_} {};
};


class BinarySearchTree {
    private:
        std::shared_ptr<ElementoArbolBinario> root = nullptr;
 
    public:
        BinarySearchTree();  // Creates empty tree

        void push(const Empleado&);

        int size() const; // Number of nodes
        void for_each(std::function<void (Empleado&)> action) const;  // Visit all the nodes
        const Empleado& find(int id) const; // Return the employee with the given id
};
