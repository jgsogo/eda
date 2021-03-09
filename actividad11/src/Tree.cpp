#include "Tree.h"

#include <algorithm>
#include <stack>
#include <iostream>
#include "Queue.h" // Let's use our queue


// Constructor for an empty tree
Tree::Tree() {}

// Constructor for a tree with the root node
Tree::Tree(const TipoDato& dato) {
    root = std::make_shared<ElementoArbol>(ElementoArbol{dato});
}

void Tree::add_subtree(const Tree& subtree) {
    if (subtree.root != nullptr) {
        root->children.push_back(subtree.root);
    }
}

int _height(std::shared_ptr<ElementoArbol> element) {
    if (element->children.empty()) {
        return 0;
    }
    else {
        int max_children_height = 0;
        for (auto child: element->children) {
            max_children_height = std::max(max_children_height, _height(child));
        }
        return 1 + max_children_height;
    }
}

int Tree::height() const {
    return _height(root);
}

int _size(std::shared_ptr<ElementoArbol> element) {
    int n_nodes = 1;
    for (auto child: element->children) {
        n_nodes += _size(child);
    }
    return n_nodes;
}

int Tree::size() const {
    return _size(root);
}

void dfs_preorder_iterativo(std::shared_ptr<ElementoArbol> root,
                            std::function<void (TipoDato&)> action) {
    std::stack<std::shared_ptr<ElementoArbol>> stack;
    stack.push(root);

    while(!stack.empty()) {
        auto elem = stack.top();
        stack.pop();
        action(elem->dato);
        // Iterate backwards
        for (auto it = elem->children.rbegin(); it != elem->children.rend(); it++) {
            stack.push(*it);
        }
    }
}

void _dfs_preorder(std::shared_ptr<ElementoArbol> root,
                   std::function<void (TipoDato&)> action) {
    action(root->dato);
    for (auto child: root->children) {
        _dfs_preorder(child, action);
    }
}

void Tree::dfs_preorder(std::function<void (TipoDato&)> action) const {
    dfs_preorder_iterativo(root, action);
}

void _dfs_postorder(std::shared_ptr<ElementoArbol> root,
                   std::function<void (TipoDato&)> action) {
    for (auto child: root->children) {
        _dfs_postorder(child, action);
    }
    action(root->dato);
}

void Tree::dfs_postorder(std::function<void (TipoDato&)> action) const {
    _dfs_postorder(root, action);
}

void _dfs_inorder(std::shared_ptr<ElementoArbol> root,
                  std::function<void (TipoDato&)> action) {
    if (!root->children.empty()) {
        _dfs_inorder(root->children[0], action);
    }
    action(root->dato);

    for (int i=1; i<root->children.size(); i++) {
        _dfs_inorder(root->children[i], action);
    }
}

void Tree::dfs_inorder(std::function<void (TipoDato&)> action) const {
    _dfs_inorder(root, action);
}

void Tree::bfs(std::function<void (TipoDato&)> action) const {
    Queue queue;
    queue.push(root);
    while (!queue.empty()) {
        QueueTipoDato elem = queue.front();
        queue.pop();
        action(elem->dato);
        for (auto child: elem->children) {
            queue.push(QueueTipoDato{child});
        }
    }
}



void _print_arithmetic_infix(std::shared_ptr<ElementoArbol> root) {
    if (!root->children.empty()) {
        std::cout << "(";
        _print_arithmetic_infix(root->children[0]);
    }
    std::cout << root->dato;

    for (int i=1; i<root->children.size(); i++) {
        _print_arithmetic_infix(root->children[i]);
        std::cout << ")";
    }
}

void Tree::print_arithmetic_infix() const {
    _print_arithmetic_infix(root);
}
