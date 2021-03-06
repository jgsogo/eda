
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "int mcd(int a, int b);")
{
    REQUIRE( mcd(10, 5) == 5 );
    REQUIRE( mcd(20, 10) == 10 );
    REQUIRE( mcd(10, 7) == 1 );
    REQUIRE( mcd(12, 10) == 2 );
}
