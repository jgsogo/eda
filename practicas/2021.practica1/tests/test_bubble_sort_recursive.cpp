
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "void bubble_sort_recursive(std::vector<int>& values);")
{
    std::vector<int> values;
    bubble_sort_recursive(values);
    REQUIRE( false );
}
