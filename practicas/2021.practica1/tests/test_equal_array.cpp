
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "bool equal(const std::array<std::array<int, 100>, 100>& lhs, const std::array<std::array<int, 100>, 100>& rhs);")
{
    std::array<std::array<int, 100>, 100> lhs;
    REQUIRE( equal(lhs, lhs) == true );

    std::array<std::array<int, 100>, 100> values;
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            values[i][j] = i*j;
        }
    }
    REQUIRE( equal(values, values) == true );
    REQUIRE( equal(values, lhs) == false );
}
