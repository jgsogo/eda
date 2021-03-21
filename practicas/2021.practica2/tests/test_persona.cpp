
#include <catch2/catch.hpp>

#include "Persona.h"


TEST_CASE( "Persona - ctor")
{
    // Check fields are assigned properly
    Persona persona("nombre", "dni", 1);
    REQUIRE( persona.get_name() == "nombre" );
    REQUIRE( persona.get_dni() == "dni" );
    REQUIRE( persona.get_gender() == 1 );
}

TEST_CASE( "Persona - operator==")
{
    // Check fields are assigned properly
    Persona persona("nombre", "dni", 1);
    REQUIRE( persona == persona );

    Persona other1("nombre", "dni", 0);
    REQUIRE( persona != other1 );

    Persona other2("nombre", "other", 1);
    REQUIRE( persona != other2 );

    Persona other3("other", "dni", 1);
    REQUIRE( persona != other3 );
}
