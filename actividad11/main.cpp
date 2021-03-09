	
#include <iostream>
#include "src/Tree.h"
 
int main() {
    Tree a("*");
    Tree b0("!");
    Tree b1("+");
    Tree c0("+");
    Tree c1(" ");
    Tree c2("10");
    Tree c3("20");
    Tree d0("2");
    Tree d1("3");

    a.add_subtree(b0);
    a.add_subtree(b1);

    b0.add_subtree(c0);
    b0.add_subtree(c1);
    b1.add_subtree(c2);
    b1.add_subtree(c3);

    c0.add_subtree(d0);
    c0.add_subtree(d1);

    Tree arbol = a;

    // Get some properties
    std::cout << "Altura: " << arbol.height() << std::endl;
    std::cout << "Tamaño/peso: " << arbol.size() << std::endl;

    auto print_node = [](const std::string& dato){
        std::cout << dato << " ";
    };

    std::cout << "DFS pre-order: ";
    arbol.dfs_preorder(print_node);
    std::cout << std::endl;

    std::cout << "DFS post-order: ";
    arbol.dfs_postorder(print_node);
    std::cout << std::endl;

    std::cout << "DFS in-order: ";
    arbol.dfs_inorder(print_node);
    std::cout << std::endl;

    std::cout << "BFS: ";
    arbol.bfs(print_node);
    std::cout << std::endl;

    arbol.print_arithmetic_infix();
}
