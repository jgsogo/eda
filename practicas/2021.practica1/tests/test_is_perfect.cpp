
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "bool is_perfect(int num);")
{
    REQUIRE( is_perfect(0) == false );
    REQUIRE( is_perfect(0) == true );
}
