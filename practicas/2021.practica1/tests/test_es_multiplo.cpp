
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "test 'bool es_multiplo(int num, int divisor);'")
{
    REQUIRE( es_multiplo(10, 5) == true );
    REQUIRE( es_multiplo(10, 25) == false );
    REQUIRE( cociente(10, 3) == false );
    REQUIRE( cociente(10, 10) == true );
}
