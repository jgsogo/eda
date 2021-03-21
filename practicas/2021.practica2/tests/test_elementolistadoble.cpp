
#include <catch2/catch.hpp>

#include "ElementoListaDoble.h"


TEST_CASE( "ElementListaDoble")
{
    Persona persona("nombre", "dni", 1);
    ElementListaDoble e1{persona};

    REQUIRE( e1.dato == persona );
    REQUIRE( e1.next == nullptr );
    REQUIRE( e1.prev == nullptr );
}
