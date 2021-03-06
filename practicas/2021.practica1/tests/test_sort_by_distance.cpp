
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "void sort_by_distance(std::vector<Point>& values, float origin_x, float origin_y);")
{
    REQUIRE( cociente(0, 5) == 0 );
    REQUIRE( cociente(10, 5) == 2 );
    REQUIRE( cociente(10, 25) == 0 );
    REQUIRE( cociente(10, 7) == 1 );
}
