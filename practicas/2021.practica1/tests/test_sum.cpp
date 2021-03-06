
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "int sum(int N);")
{
    REQUIRE( sum(0) == 0 );
    REQUIRE( sum(1) == 1 );
    REQUIRE( sum(5) == 15 );
    REQUIRE( sum(10) == 55 );
}
