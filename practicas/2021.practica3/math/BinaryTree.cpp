
#include "BinaryTree.h"


namespace {
    void _dfs_inorder(std::shared_ptr<ElementoArbolBinario> root, std::function<void (const std::string&)> action) {
        if (root->left != nullptr) {
            _dfs_inorder(root->left, action);
        }

        action(root->dato);

        if (root->right != nullptr) {
            _dfs_inorder(root->right, action);
        }
    }

    void _dfs_postorder(std::shared_ptr<ElementoArbolBinario> root, std::function<void (const std::string&)> action) {
        if (root->left != nullptr) {
            _dfs_postorder(root->left, action);
        }

        if (root->right != nullptr) {
            _dfs_postorder(root->right, action);
        }

        action(root->dato);
    }
}


BinaryTree::BinaryTree(const std::string& dato) {
    root = std::make_shared<ElementoArbolBinario>(dato);
}

void BinaryTree::add_left(const BinaryTree& tree) {
    root->left = tree.root;
}
void BinaryTree::add_right(const BinaryTree& tree) {
    root->right = tree.root;
}

void BinaryTree::dfs_inorder(std::function<void (const std::string&)> action) const {
    _dfs_inorder(root, action);
}

void BinaryTree::dfs_postorder(std::function<void (const std::string&)> action) const {
    _dfs_postorder(root, action);
}

