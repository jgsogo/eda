
#include <iostream>
#include "math/BinaryTree.h"

int main() {
    //Expresión "- 3 * log (2 + 5)"
    std::cout << "Expresion: - 3 * log (2 + 5)" << std::endl;
    
    // (2+5)
    BinaryTree _25{"+"};
    _25.add_left({"2"});
    _25.add_right({"5"});

    // log (2 + 5)
    BinaryTree log25{"log"};
    log25.add_right(_25);

    // - 3
    BinaryTree _3{"-"};
    _3.add_right({"3"});

    // -3 * log(2+5)
    BinaryTree expr{"*"};
    expr.add_left(_3);
    expr.add_right(log25);

    // Notación infija
    std::cout << "Notacion infija" << std::endl;
    expr.dfs_inorder([] (const std::string& node) {
        std::cout << node << " ";
    });
    std::cout << std::endl;

    // Notación postfija
    std::cout << "Notacion postfija" << std::endl;
    expr.dfs_postorder([](const std::string& node) {
        std::cout << node << " ";
    });

}