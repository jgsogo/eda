
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "bool equal(const std::vector<int>& lhs, const std::vector<int>& rhs);")
{
    const std::vector<int> empty;
    REQUIRE( equal(empty, empty) == true );

    const std::vector<int> single{1};
    REQUIRE( equal(single, single) == true );
    REQUIRE( equal(single, empty) == false );

    const std::vector<int> values{1, 2, 3, 4, 5};
    REQUIRE( equal(values, values) == true );
    REQUIRE( equal(values, single) == false );
    REQUIRE( equal(values, empty) == false );
}
