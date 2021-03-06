
#include <catch2/catch.hpp>

#include "practica1.h"
#include <iostream>

TEST_CASE( "int invertir(int num);" )
{
    REQUIRE( invertir(1) == 1 );
    REQUIRE( invertir(2) == 2 );
    REQUIRE( invertir(1234) == 4321 );
    REQUIRE( invertir(1000) == 1 );
    REQUIRE( invertir(12) == 21 );
}
