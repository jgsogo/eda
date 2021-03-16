#pragma once

#include <ostream>

class Avion { // TipoDato
    public:
        Avion(int hora_salida, int minuto_salida, bool is_jet, bool is_transplante);
        
        // Order criteria based on priority
        bool operator<=(const Avion& other) const;
        bool operator>(const Avion& other) const;
        
        // Overloaded << operator to print information
        friend std::ostream& operator<<(std::ostream& os, const Avion& dt);
    
    private:
        int hora_salida;
        int minuto_salida;
        bool is_transplante;
        bool is_jet;
};

std::ostream& operator<<(std::ostream& os, const Avion& dt);
