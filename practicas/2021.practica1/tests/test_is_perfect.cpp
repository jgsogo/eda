
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "bool is_perfect(int num);")
{
    REQUIRE( is_perfect(6) == true );
    REQUIRE( is_perfect(28) == true );
    REQUIRE( is_perfect(496) == true );

    REQUIRE( is_perfect(1) == false );
    REQUIRE( is_perfect(2) == false );
    REQUIRE( is_perfect(158) == false );
}
