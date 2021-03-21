
#include <iostream>
#include "src/AVLTree.h"

void print(AVLTree tree) {
    std::cout << "AVLTree" << std::endl;
    std::cout << " - height: " << tree.height() << std::endl;
    std::cout << " - size: " << tree.size() << std::endl;
    if (tree.size() != 0) {
        std::cout << " - min: " << tree.min() << std::endl;
        std::cout << " - max: " << tree.max() << std::endl;
    }

    std::function<void (const TipoDato&)> action = [](const TipoDato& dato){
        std::cout << dato << std::endl;
    };
    tree.dfs_inorder(action);
}

int main() {
    AVLTree tree;
    print(tree);
    for (auto v: {23, 45, 67, 54}) {
        tree.push(v);
    }

    tree.remove(23);
    tree.remove(67);
    tree.remove(45);
    tree.remove(54);
    print(tree);
}
