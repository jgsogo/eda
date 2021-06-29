
#include <iostream>
#include "math/BinaryTree.h"

int main() {
    //Expresión: "(2*(3+4)-10)/2"
    std::cout << "Expresion: (2*(3+4)-10)/2" << std::endl;

    // 3+4
    BinaryTree _34{"+"};
    _34.add_left({"3"});
    _34.add_right({"4"});

    // 2 * (3+4)
    BinaryTree _234{"*"};
    _234.add_left({"2"});
    _234.add_right(_34);

    // 2*(3+4) - 10
    BinaryTree _m10{"-"};
    _m10.add_left(_234);
    _m10.add_right({"10"});

    // X / 2
    BinaryTree expr{"/"};
    expr.add_left(_m10);
    expr.add_right({"10"});

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