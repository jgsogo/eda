
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "bool equal(const std::vector<int>& lhs, const std::vector<int>& rhs);")
{
    const std::vector<int> empty;
    REQUIRE( equal(empty, empty) == true );

    const std::vector<int> single;
    REQUIRE( equal(single, single) == true );
    REQUIRE( equal(single, empty) == false );
}
