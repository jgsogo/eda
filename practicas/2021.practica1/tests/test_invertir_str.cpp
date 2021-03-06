
#include <catch2/catch.hpp>

#include "practica1.h"

TEST_CASE( "std::string invertir(const std::string& input); -- dummy")
{
    CHECK_THAT( invertir(""), Catch::Matchers::Matches("") );
    CHECK_THAT( invertir("a"), Catch::Matchers::Matches("a") );
}

TEST_CASE( "std::string invertir(const std::string& input);")
{
    REQUIRE( invertir("as") == std::string{"sa"} );
    REQUIRE( invertir("12345") == std::string{"54321"} );
}
