
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "bool es_multiplo(int num, int divisor);")
{
    REQUIRE( es_multiplo(10, 5) == true );
    REQUIRE( es_multiplo(10, 2) == true );
    REQUIRE( es_multiplo(10, 10) == true );
    REQUIRE( es_multiplo(10, 25) == false );
    REQUIRE( es_multiplo(10, 3) == false );
}
