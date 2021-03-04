
#include <catch2/catch.hpp>
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>

#include "check_braces.h"


TEST_CASE( "check_braces - Empty string", "[test_check_braces.cpp]" )
{
    REQUIRE( check_braces("") == true );
}

TEST_CASE( "check_braces - Simple ones", "[test_check_braces.cpp]" )
{
    REQUIRE( check_braces("()") == true );
    REQUIRE( check_braces("[]") == true );
    REQUIRE( check_braces("(") == false );
    REQUIRE( check_braces(")") == false );
    REQUIRE( check_braces("[") == false );
    REQUIRE( check_braces("]") == false );
}

TEST_CASE( "check_braces - Mismatch type", "[test_check_braces.cpp]" )
{
    REQUIRE( check_braces("(]") == false );
    REQUIRE( check_braces("[)") == false );
}

TEST_CASE( "check_braces - Mismatch number", "[test_check_braces.cpp]" )
{
    REQUIRE( check_braces("()]") == false );
    REQUIRE( check_braces("[])") == false );
    REQUIRE( check_braces("[()") == false );
    REQUIRE( check_braces("([]") == false );
}

TEST_CASE( "check_braces - Valid expressions", "[test_check_braces.cpp]" )
{
    REQUIRE( check_braces("[]([][()])") == true );
    REQUIRE( check_braces("[([])[][()()]]") == true );
}
