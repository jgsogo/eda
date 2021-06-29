#include "Empleado.h"


Empleado::Empleado(int id, bool is_boss) : id_{id}, is_boss_{is_boss} {}

int Empleado::get_id() const {
    return id_;
}

bool Empleado::is_boss() const {
    return is_boss_;
}

bool Empleado::operator<(const Empleado& other) const {
    return id_ < other.id_;
}

bool Empleado::operator>(const Empleado& other) const {
    return id_ > other.id_;
}

bool Empleado::operator==(const Empleado& other) const {
    return id_ == other.id_;
}

std::ostream& operator<<(std::ostream& os, const Empleado& empleado) {
    os << "Empleado " << empleado.id_ <<  " (" << empleado.is_boss_ << ")";
    return os;
}
