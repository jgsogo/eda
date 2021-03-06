
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "void sort_by_distance(std::vector<Point>& values, float origin_x, float origin_y);")
{
    std::vector<Point> values;
    sort_by_distance(values, 1, 1);
    REQUIRE( false );
}
