#include "AVLTree.h"

#include <algorithm>

// Constructor for an empty tree
AVLTree::AVLTree() {}

// Constructor for a tree with the root node
AVLTree::AVLTree(const TipoDato& dato) {
    root = std::make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
}

int _height(std::shared_ptr<ElementoArbolBinario> element) {
    if (element == nullptr) {
        return -1;
    }
    else {
        int height_left = _height(element->left);
        int height_right = _height(element->right);
        return 1 + std::max(height_left, height_right);
    }
}

int AVLTree::height() const {
    return _height(root);
}

int _size(std::shared_ptr<ElementoArbolBinario> element) {
    if (element == nullptr) {
        return 0;
    }
    else {
        int size_left = _size(element->left);
        int size_right = _size(element->right);
        return 1 + size_left + size_right;
    }
}

int AVLTree::size() const {
    return _size(root);
}


void _dfs_inorder(std::shared_ptr<ElementoArbolBinario> elem,
                  std::function<void (TipoDato&)> action) {
    if (elem->left != nullptr) {
        _dfs_inorder(elem->left, action);
    }
    action(elem->dato);
    if (elem->right != nullptr) {
        _dfs_inorder(elem->right, action);
    }

}

void AVLTree::dfs_inorder(std::function<void (const TipoDato&)> action) const {
    if (root != nullptr) {
        _dfs_inorder(root, action);
    }
}

const TipoDato& _min(std::shared_ptr<ElementoArbolBinario> element) {
    if (element->left != nullptr) {
        return _min(element->left);
    }
    else {
        return element->dato;
    }
}

const TipoDato& AVLTree::min() const {
    return _min(root);
}

const TipoDato& _max(std::shared_ptr<ElementoArbolBinario> element) {
    if (element->right != nullptr) {
        return _max(element->right);
    }
    else {
        return element->dato;
    }
}

const TipoDato& AVLTree::max() const {
    return _max(root);
}


bool _find(std::shared_ptr<ElementoArbolBinario> element, 
           const TipoDato& dato) {
    // Handle corner case
    if (element == nullptr) {
        return false;
    }
 
    // Do actual work
    if (element->dato > dato) {
        return _find(element->left, dato);
    }
    else if (element->dato < dato) {
        return _find(element->right, dato);
    }
    else {
        return element->dato == dato;
    }
}
 
bool AVLTree::find(const TipoDato& dato) const {
    return _find(root, dato);
}

	
void _push(std::shared_ptr<ElementoArbolBinario>& element, // Note the reference
           const TipoDato& dato) {
    // Handle corner case
    if (element == nullptr) {
        element = std::make_shared<ElementoArbolBinario>(dato);
        return;
    }
 
    // Do actual work
    if (element->dato > dato) {
        _push(element->left, dato);
    }
    else if (element->dato < dato) {
        _push(element->right, dato);
    }
    else {
        // It is a duplicated element! Do nothing, raise exception,...
    }
}
 
void AVLTree::push(const TipoDato& dato) {
    return _push(root, dato);
    rebalance();
}

void AVLTree::remove(const TipoDato& dato) {
    // Find the element (keep a reference to its parent)
    auto elem = root;
    std::shared_ptr<ElementoArbolBinario> parent = nullptr;
    while (elem != nullptr) {
        if (elem->dato == dato) {
            break;
        }
        parent = elem;
        elem = (dato < elem->dato) ? elem->left : elem->right;
    }
 
    // If not found, nothing to do
    if (elem == nullptr) {
        return;
    }
 
    // If it has two childs, replace with the max element in the subtree
    if (elem->left != nullptr && elem->right != nullptr) {
        elem->dato = _max(elem->left);
 
        // Now the element to remove is the one at that max position
        parent = elem;
        elem = elem->left;
        while (elem->right != nullptr) {
            parent = elem;
            elem = elem->right;
        }
    }
 
    // Now the node to remove only has 1 or 0 childs
    auto next = (elem->left != nullptr) ? elem->left : elem->right;
    if (parent == nullptr) {
        root = next;
    }
    else {
        if (parent->left == elem) {
            parent->left = next;
        }
        else {
            parent->right = next;
        }
    }
    rebalance();
}


int factor_equilibrio(std::shared_ptr<ElementoArbolBinario> element) {
    return _height(element->right) - _height(element->left);
}

void rotate_left(std::shared_ptr<ElementoArbolBinario>& element) { // Note the reference
    auto old_parent = element;
    element = element->left;
    old_parent->left = element->right;
    element->right = old_parent;
}

void rotate_right(std::shared_ptr<ElementoArbolBinario>& element) { // Note the reference
    auto old_parent = element;
    element = element->right;
    old_parent->right = element->left;
    element->left = old_parent;
}


void _rebalance(std::shared_ptr<ElementoArbolBinario>& element) { // Note the reference
    // DFS post-order strategy:
    if (element->left) {
        _rebalance(element->left);
    }
    else if (element->right) {
        _rebalance(element->right);
    }
 
    if (factor_equilibrio(element) == -2) {
        if (factor_equilibrio(element->left) == 1) {
            // First, rotate the child right
            rotate_right(element->left);
        }
        rotate_left(element);
    }
    else if (factor_equilibrio(element) == 2) {
        if (factor_equilibrio(element->right) == -1) {
            // First, rotate the child left
            rotate_left(element->right);
        }
        rotate_right(element);
    }
}

void AVLTree::rebalance() {
    if (root != nullptr) {
        _rebalance(root);
    }
}

