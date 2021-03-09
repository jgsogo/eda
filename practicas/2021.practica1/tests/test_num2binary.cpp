
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "std::string num2binary(int num);")
{
    REQUIRE( num2binary(0) == "0" );
    REQUIRE( num2binary(1) == "1" );
    REQUIRE( num2binary(2) == "10" );
    REQUIRE( num2binary(3) == "11" );
    REQUIRE( num2binary(8) == "1000" );
    REQUIRE( num2binary(31) == "11111" );
}
