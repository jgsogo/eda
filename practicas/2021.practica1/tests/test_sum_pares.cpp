
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "int sum_pares(int N);")
{
    REQUIRE( sum_pares(0) == 0 );
    REQUIRE( sum_pares(1) == 0 );
    REQUIRE( sum_pares(5) == 6 );
    REQUIRE( sum_pares(6) == 12 );
}
