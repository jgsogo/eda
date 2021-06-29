#include <iostream>

#include "src/Database.h"
#include "src/FilterDatabase.h"

int main() {
    // Build the tree of employees
    BinarySearchTree tree;
    tree.push(Empleado{10, false});
    tree.push(Empleado{8, false});
    tree.push(Empleado{15, true});
    tree.push(Empleado{12, false});
    tree.push(Empleado{20, false});
    tree.push(Empleado{9, true});
    tree.push(Empleado{14, false});

    std::cout << "All the company:" << std::endl;
    tree.for_each([](const Empleado& employee){
        std::cout << employee << std::endl;
    });

    // Get employees and managers
    BinarySearchTree employees, managers;
    filter_database(tree, employees, managers);

    std::cout << std::endl << "Managers:" << std::endl;
    managers.for_each([](const Empleado& employee){
        std::cout << employee << std::endl;
    });

    std::cout << std::endl << "Employees:" << std::endl;
    employees.for_each([](const Empleado& employee){
        std::cout << employee << std::endl;
    });
}
