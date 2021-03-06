
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "void bubble_sort_recursive(std::vector<int>& values); -- dummy scenarios")
{
    // Dummy cases
    std::vector<int> empty;
    bubble_sort_recursive(empty);
    
    std::vector<int> single{23};
    bubble_sort_recursive(single);
    REQUIRE(single == std::vector<int>{23});
}

TEST_CASE( "void bubble_sort_recursive(std::vector<int>& values);")
{
    // Dummy cases
    std::vector<int> values{6, 5, 4, 3, 2, 1};
    bubble_sort_recursive(values);
    REQUIRE( values == std::vector<int>{1, 2, 3, 4, 5, 6} );
}
