#pragma once

#include "ElementoArbol.h"


class Tree {
    protected:
        std::shared_ptr<ElementoArbol> root = nullptr;
 
    public:
        Tree();  // Creates empty tree
        Tree(const TipoDato& dato);  // Creates tree with root node
 
        // Member functions (properties of the tree structure)
        int height() const;
        int size() const; // Returns number of nodes
 
        // A way to add subtrees to an existing tree
        void add_subtree(const Tree& subtree);

        // Different traverse strategies
        void dfs_preorder(std::function<void (TipoDato&)> action) const;
        void dfs_postorder(std::function<void (TipoDato&)> action) const;
        void dfs_inorder(std::function<void (TipoDato&)> action) const;

        void bfs(std::function<void (TipoDato&)> action) const;

        void print_arithmetic_infix() const;
};
