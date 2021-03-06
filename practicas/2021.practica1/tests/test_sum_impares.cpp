
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE("test 'int sum_impares(int N);'")
{
    REQUIRE( es_par(1) == false );
    REQUIRE( es_par(2) == true );
    REQUIRE( es_par(25) == false );
    REQUIRE( es_par(1024) == true );
}
