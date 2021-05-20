#include "FilterDatabase.h"

void filter_database(const BinarySearchTree& all, BinarySearchTree& employees, BinarySearchTree& managers) {
    all.for_each([&](const Empleado& employee) {
        if (employee.is_boss()) {
            managers.push(employee);
        }
        else {
            employees.push(employee);
        }
    });
}
