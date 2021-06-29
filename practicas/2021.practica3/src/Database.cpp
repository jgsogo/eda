#include "Database.h"

#include <list>

namespace {
    int _size(std::shared_ptr<ElementoArbolBinario> elem) {
        if (elem == nullptr) {
            return 0;
        }
        return 1 + _size(elem->left) + _size(elem->right);
    }

    const Empleado& _find(std::shared_ptr<ElementoArbolBinario> elem, const Empleado& employee) {
        if (elem == nullptr) {
            throw std::runtime_error("Employee not found");
        }

        if (elem->dato == employee) {
            return elem->dato;
        }
        else if (elem->dato > employee) {
            return _find(elem->left, employee);
        }
        else {
            return _find(elem->right, employee);
        }
    }

    void _push(std::shared_ptr<ElementoArbolBinario>& elem, const Empleado& employee) {
        if (elem == nullptr) {
            elem = std::make_shared<ElementoArbolBinario>(employee);
            return;
        }

        if (elem->dato > employee) {
            _push(elem->left, employee);
        }
        else if (elem->dato < employee) {
            _push(elem->right, employee);
        }
        else {
            throw std::runtime_error("Employee already exists");
        }
    }
}

BinarySearchTree::BinarySearchTree() {}

void BinarySearchTree::push(const Empleado& employee) {
    _push(root, employee);
}

int BinarySearchTree::size() const {
    return _size(root);
}

void BinarySearchTree::for_each(std::function<void (Empleado&)> action) const {
    if (root == nullptr) {
        return;
    }

    // I will use BFS with an auxiliary Queue
    std::list<std::shared_ptr<ElementoArbolBinario>> queue;
    queue.push_back(root);
    while (!queue.empty()) {
        // Get the element at front
        auto elem = queue.front();
        queue.pop_front();
        
        // Execute action on it
        action(elem->dato);

        // Add child (if any)
        if (elem->left) {
            queue.push_back(elem->left);
        }
        if (elem->right) {
            queue.push_back(elem->right);
        }
    };
}

const Empleado& BinarySearchTree::find(int id) const {
    Empleado aux{id, false}; // Create an auxiliary Empleado to use for search
    return _find(root, aux);
}
