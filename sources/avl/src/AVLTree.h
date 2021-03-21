	
#pragma once

#include <functional>
#include "ElementoArbolBinario.h"


class AVLTree {
    protected:
        std::shared_ptr<ElementoArbolBinario> root = nullptr;
 
    public:
        AVLTree();  // Creates empty tree
        AVLTree(const TipoDato& dato);  // Creates tree with root node
 
        // Same as BinaryTree
        int height() const;
        int size() const; // Number of nodes
 
        // Get data
        const TipoDato& min() const;
        const TipoDato& max() const;
 
        // Traverse the tree
        void dfs_inorder(std::function<void (const TipoDato&)> action) const;
 
        // Operations
        bool find(const TipoDato&) const;
        void push(const TipoDato&);
        void remove(const TipoDato&);

    private:
        void rebalance();
};
