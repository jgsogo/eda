
#include <catch2/catch.hpp>

#include "ElementoListaDoble.h"


TEST_CASE( "ElementoListaDoble")
{
    Persona persona("nombre", "dni", 1);
    ElementoListaDoble e1{persona};

    REQUIRE( e1.dato == persona );
    REQUIRE( e1.next == nullptr );
    REQUIRE( e1.prev == nullptr );
}
