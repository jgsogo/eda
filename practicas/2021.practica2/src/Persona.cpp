#include "Persona.h"

Persona::Persona(const std::string& name, const std::string& dni, int gender)
{
    this->dni= dni;
    this->gender = gender;
    this->name = name;

}
const std::string& Persona::get_name() const{
    return this->name;
}
int Persona::get_gender() const{
    return this->gender;
}
const std::string& Persona::get_dni() const{
    return this->dni;
}
bool Persona::operator==(const Persona& other) const{
   return (other.dni == this->dni && other.gender == this->gender &&
              other.name == this->name)?true:false;

}
