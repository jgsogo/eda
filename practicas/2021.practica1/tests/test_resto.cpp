
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "int resto(int dividendo, int divisor);")
{
    REQUIRE( resto(0, 5) == 0 );
    REQUIRE( resto(10, 5) == 0 );
    REQUIRE( resto(10, 25) == 10 );
    REQUIRE( resto(10, 7) == 3 );
}
