#include "Avion.h"

#include <iostream>



Avion::Avion(int hora_salida, int minuto_salida, bool is_transplante, bool is_jet) 
    : hora_salida(hora_salida), minuto_salida(minuto_salida), is_transplante(is_transplante), is_jet(is_jet) {

}

// Order criteria based on priority
bool Avion::operator<=(const Avion& other) const {
    if (is_transplante && !other.is_transplante) {
        return true;
    }
    else if (other.is_transplante && !is_transplante) {
        return false;
    }
    else { 
        // Both have the same value for is_transplante
        if (is_jet && !other.is_jet) {
            return true;
        }
        else if (other.is_jet && !is_jet) {
            return false;
        }
        else {
            // Both have the same value for is_jet
            if (hora_salida == other.hora_salida) {
                return minuto_salida <= other.minuto_salida;
            }
            else {
                return hora_salida <= other.hora_salida;
            }
        }
    }
}

bool Avion::operator>(const Avion& other) const {
    return !(*this <= other);
}


std::ostream& operator<<(std::ostream& os, const Avion& dt) {
    os << "Avion " << dt.hora_salida << ":" << dt.minuto_salida;
    if (dt.is_jet) {
        os << " (jet)";
    }
    if (dt.is_transplante) {
        os << " (transplante)";
    }
    return os;
}
