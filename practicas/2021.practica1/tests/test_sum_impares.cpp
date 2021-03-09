
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE("int sum_impares(int N);")
{
    REQUIRE( sum_impares(0) == 0 );
    REQUIRE( sum_impares(1) == 1 );
    REQUIRE( sum_impares(5) == 9 );
    REQUIRE( sum_impares(6) == 9 );
}
