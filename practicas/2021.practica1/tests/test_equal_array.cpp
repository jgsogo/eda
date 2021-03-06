
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "bool equal(const std::array<std::array<int, 100>, 100>& lhs, const std::array<std::array<int, 100>, 100>& rhs);")
{
    std::array<std::array<int, 100>, 100> lhs;
    REQUIRE( equal(lhs, lhs) == true );
}
