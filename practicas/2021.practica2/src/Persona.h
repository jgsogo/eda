
#include <string>

class Persona {
    public:
        Persona(const std::string& name, const std::string& dni, int gender);

        const std::string& get_name() const;
        int get_gender() const;
        const std::string& get_dni() const;
        bool operator==(const Persona& other) const;
    private:
        int gender; 
        std::string name;
        std::string dni;
};
