
#include <catch2/catch.hpp>

#include "practica1.h"

TEST_CASE( "std::string invertir(const std::string& input);")
{
    CHECK_THAT( invertir(""), Catch::Matchers::Matches("") );
    CHECK_THAT( invertir("a"), Catch::Matchers::Matches("a") );
    CHECK_THAT( invertir("as"), Catch::Matchers::Matches("sa") );
    CHECK_THAT( invertir("12345"), Catch::Matchers::Matches("54321") );
}
