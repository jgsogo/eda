
#include <catch2/catch.hpp>
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>

#include "DoubleLinkedList.h"


TEST_CASE( "iterate_reveerse - Empty list", "[test_iterate_reverse.cpp]" )
{
    DoubleLinkedList list;
    std::vector<int> datos;
    auto collect = [&](TipoDato& dato) { datos.push_back(dato.num); };
    list.for_each(collect);
    REQUIRE( datos.size() == 0 );
    list.for_each_reverse(collect);
    REQUIRE( datos.size() == 0 );
}

