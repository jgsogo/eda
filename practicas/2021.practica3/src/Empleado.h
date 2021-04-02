#pragma once

#include <iostream>

class Empleado {
    public:
        Empleado(int id, bool is_boss);

        int get_id() const;
        bool is_boss() const;

        bool operator<(const Empleado& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Empleado& empleado);
    private:
        int id_;
        bool is_boss_;
};

std::ostream& operator<<(std::ostream& os, const Empleado& empleado);
