
#include <catch2/catch.hpp>
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>

#include "sort_algorithms.h"


TEST_CASE( "quick_sort - Empty vector", "[test_quick_sort.cpp]" )
{
    // Nothing to check, just that it doesn't throw
    std::vector<float> values{};
    quick_sort(values, 0, values.size()-1);
    REQUIRE( values.size() == 0 );
}

TEST_CASE( "quick_sort - Vectors with one element", "[test_quick_sort.cpp]" )
{
    std::vector<float> values{0.0};
    quick_sort(values, 0, values.size()-1);
    REQUIRE( values == std::vector<float>{0.0} );
}

TEST_CASE( "quick_sort - Vectors with two elements", "[test_quick_sort.cpp]" )
{
    std::vector<float> expected{0.1, 0.2};

    SECTION( "already ordered" ) {
        std::vector<float> values{0.1, 0.2};
        quick_sort(values, 0, values.size()-1);
        REQUIRE( values == expected );
    }

    SECTION( "reverse order" ) {
        std::vector<float> values{0.2, 0.1};
        quick_sort(values, 0, values.size()-1);
        REQUIRE( values == expected );
    }

    SECTION( "equal elements" ) {
        std::vector<float> values{0.1, 0.1};
        quick_sort(values, 0, values.size()-1);
        REQUIRE( values == std::vector<float>{0.1, 0.1} );
    }
}

TEST_CASE( "quick_sort - Vectors with three elements", "[test_quick_sort.cpp]" )
{
    std::vector<float> expected{0.1, 0.2, 0.3};

    SECTION( "already ordered" ) {
        std::vector<float> values{0.1, 0.2, 0.3};
        quick_sort(values, 0, values.size()-1);
        REQUIRE( values == expected );
    }

    SECTION( "reverse order" ) {
        std::vector<float> values{0.3, 0.2, 0.1};
        quick_sort(values, 0, values.size()-1);
        REQUIRE( values == expected );
    }

    SECTION( "mix order 1" ) {
        std::vector<float> values{0.2, 0.3, 0.1};
        quick_sort(values, 0, values.size()-1);
        REQUIRE( values == expected );
    }

    SECTION( "mix order 2" ) {
        std::vector<float> values{0.1, 0.3, 0.2};
        quick_sort(values, 0, values.size()-1);
        REQUIRE( values == expected );
    }

    SECTION( "mix order 3" ) {
        std::vector<float> values{0.3, 0.1, 0.2};
        quick_sort(values, 0, values.size()-1);
        REQUIRE( values == expected );
    }

    SECTION( "mix order 4" ) {
        std::vector<float> values{0.2, 0.1, 0.3};
        quick_sort(values, 0, values.size()-1);
        REQUIRE( values == expected );
    }

    SECTION( "equal elements" ) {
        std::vector<float> values{0.1, 0.1, 0.1};
        quick_sort(values, 0, values.size()-1);
        REQUIRE( values == std::vector<float>{0.1, 0.1, 0.1} );
    }
}

SCENARIO( "quick_sort - Vectors with more elements", "[test_quick_sort.cpp]" )
{
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    std::default_random_engine generator;

    std::vector<float> input_data(1000);
    std::generate(input_data.begin(), input_data.end(), [&]() { return distribution(generator); });

    std::vector<float> expected(input_data.size());
    std::partial_sort_copy(std::begin(input_data), std::end(input_data), std::begin(expected), std::end(expected));

    SECTION( "random input" ) {
        quick_sort(input_data, 0, input_data.size()-1);
        REQUIRE( input_data == expected );
    }
}

SCENARIO( "quick_sort - Issue #12", "[test_quick_sort.cpp]" )
{
    std::vector<float> input_data{1.2, 4.5, 7.8, 9.7, 4.2};

    std::vector<float> expected(input_data.size());
    std::partial_sort_copy(std::begin(input_data), std::end(input_data), std::begin(expected), std::end(expected));

    SECTION( "random input" ) {
        quick_sort(input_data, 0, input_data.size()-1);
        REQUIRE( input_data == expected );
    }
}

SCENARIO( "quick_sort - Half lower vector", "[test_quick_sort.cpp]" )
{
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    std::default_random_engine generator;

    std::vector<float> input_data(10);
    std::generate(input_data.begin(), input_data.end(), [&]() { return distribution(generator); });

    std::vector<float> expected{input_data.begin(), input_data.end()};
    int offset = 5;
    std::partial_sort_copy(std::begin(input_data), std::begin(input_data) + offset + 1, std::begin(expected), std::begin(expected) + offset + 1);

    SECTION( "random input" ) {
        quick_sort(input_data, 0, offset);
        REQUIRE( input_data == expected );
    }
}

SCENARIO( "quick_sort - Half upper vector", "[test_quick_sort.cpp]" )
{
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    std::default_random_engine generator;

    std::vector<float> input_data(10);
    std::generate(input_data.begin(), input_data.end(), [&]() { return distribution(generator); });

    std::vector<float> expected{input_data.begin(), input_data.end()};
    int offset = 5;
    std::partial_sort_copy(std::begin(input_data) + offset, std::end(input_data), std::begin(expected) + offset, std::end(expected));

    SECTION( "random input" ) {
        quick_sort(input_data, offset, input_data.size()-1);
        REQUIRE( input_data == expected );
    }
}
