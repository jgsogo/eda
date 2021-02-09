
#include <catch2/catch.hpp>

#include "binary_search.h"

SCENARIO( "Empty vector", "[test_binary_search.cpp]" )
{
    REQUIRE( binary_search(std::vector<int>{}, 23) == false );  // Empty vector
}

SCENARIO( "Vectors with one element", "[test_binary_search.cpp]" )
{
    REQUIRE( binary_search(std::vector<int>{1}, 1) == true );  // Single element found
    REQUIRE( binary_search(std::vector<int>{1}, 8) == false ); // Single element not found
}

SCENARIO( "Vectors with two elements", "[test_binary_search.cpp]" )
{
    REQUIRE( binary_search(std::vector<int>{1, 3}, 1) == true );
    REQUIRE( binary_search(std::vector<int>{1, 3}, 3) == true );

    REQUIRE( binary_search(std::vector<int>{1, 3}, 8) == false );
}

SCENARIO( "Vectors with three elements", "[test_binary_search.cpp]" )
{
    REQUIRE( binary_search(std::vector<int>{1, 3, 5}, 1) == true );
    REQUIRE( binary_search(std::vector<int>{1, 3, 5}, 3) == true );
    REQUIRE( binary_search(std::vector<int>{1, 3, 5}, 5) == true );

    REQUIRE( binary_search(std::vector<int>{1, 3, 5}, 8) == false );
}

SCENARIO( "Vectors with more elements", "[test_palindrome.cpp]" )
{
    REQUIRE( binary_search(std::vector<int>{1, 3, 5, 8, 11, 13, 21, 44}, 1) == true);
    REQUIRE( binary_search(std::vector<int>{1, 3, 5, 8, 11, 13, 21, 44}, 3) == true);
    REQUIRE( binary_search(std::vector<int>{1, 3, 5, 8, 11, 13, 21, 44}, 5) == true);
    REQUIRE( binary_search(std::vector<int>{1, 3, 5, 8, 11, 13, 21, 44}, 8) == true);
    REQUIRE( binary_search(std::vector<int>{1, 3, 5, 8, 11, 13, 21, 44}, 11) == true);
    REQUIRE( binary_search(std::vector<int>{1, 3, 5, 8, 11, 13, 21, 44}, 13) == true);
    REQUIRE( binary_search(std::vector<int>{1, 3, 5, 8, 11, 13, 21, 44}, 21) == true);
    REQUIRE( binary_search(std::vector<int>{1, 3, 5, 8, 11, 13, 21, 44}, 44) == true);

    REQUIRE( binary_search(std::vector<int>{1, 3, 5, 8, 11, 13, 21, 44}, 52) == false);
}
