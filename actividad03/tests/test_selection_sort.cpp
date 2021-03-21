
#include <catch2/catch.hpp>
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>

#include "sort_algorithms.h"


TEST_CASE( "selection_sort - Empty vector", "[test_selection_sort.cpp]" )
{
    // Nothing to check, just that it doesn't throw
    std::vector<float> values{};
    selection_sort(values);
    REQUIRE( values.size() == 0 );
}

TEST_CASE( "selection_sort - Vectors with one element", "[test_selection_sort.cpp]" )
{
    std::vector<float> values{0.0};
    selection_sort(values);
    REQUIRE( values == std::vector<float>{0.0} );
}

TEST_CASE( "selection_sort - Vectors with two elements", "[test_selection_sort.cpp]" )
{
    std::vector<float> expected{0.1, 0.2};

    SECTION( "already ordered" ) {
        std::vector<float> values{0.1, 0.2};
        selection_sort(values);
        REQUIRE( values == expected );
    }

    SECTION( "reverse order" ) {
        std::vector<float> values{0.2, 0.1};
        selection_sort(values);
        REQUIRE( values == expected );
    }

    SECTION( "equal elements" ) {
        std::vector<float> values{0.1, 0.1};
        selection_sort(values);
        REQUIRE( values == std::vector<float>{0.1, 0.1} );
    }
}

TEST_CASE( "selection_sort - Vectors with three elements", "[test_selection_sort.cpp]" )
{
    std::vector<float> expected{0.1, 0.2, 0.3};

    SECTION( "already ordered" ) {
        std::vector<float> values{0.1, 0.2, 0.3};
        selection_sort(values);
        REQUIRE( values == expected );
    }

    SECTION( "reverse order" ) {
        std::vector<float> values{0.3, 0.2, 0.1};
        selection_sort(values);
        REQUIRE( values == expected );
    }

    SECTION( "mix order 1" ) {
        std::vector<float> values{0.2, 0.3, 0.1};
        selection_sort(values);
        REQUIRE( values == expected );
    }

    SECTION( "mix order 2" ) {
        std::vector<float> values{0.1, 0.3, 0.2};
        selection_sort(values);
        REQUIRE( values == expected );
    }

    SECTION( "mix order 3" ) {
        std::vector<float> values{0.3, 0.1, 0.2};
        selection_sort(values);
        REQUIRE( values == expected );
    }

    SECTION( "mix order 4" ) {
        std::vector<float> values{0.2, 0.1, 0.3};
        selection_sort(values);
        REQUIRE( values == expected );
    }

    SECTION( "equal elements" ) {
        std::vector<float> values{0.1, 0.1, 0.1};
        selection_sort(values);
        REQUIRE( values == std::vector<float>{0.1, 0.1, 0.1} );
    }
}

TEST_CASE( "selection_sort - Vectors with more elements", "[test_selection_sort.cpp]" )
{
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    std::default_random_engine generator;

    std::vector<float> input_data(1000);
    std::generate(input_data.begin(), input_data.end(), [&]() { return distribution(generator); });

    std::vector<float> expected(input_data.size());
    std::partial_sort_copy(std::begin(input_data), std::end(input_data), std::begin(expected), std::end(expected));

    SECTION( "random input" ) {
        selection_sort(input_data);
        REQUIRE( input_data == expected );
    }
}
