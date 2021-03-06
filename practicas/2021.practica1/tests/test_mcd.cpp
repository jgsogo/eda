
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "test 'int mcd(int a, int b);'")
{
    REQUIRE( mcd(0, 5) == 0 );
    REQUIRE( mcd(10, 5) == 5 );
    REQUIRE( mcd(20, 10) == 10 );
    REQUIRE( cociente(10, 7) == 1 );
}
