
#include <catch2/catch.hpp>
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>

#include "DoubleLinkedList.h"


TEST_CASE( "iterate_reveerse - Empty list", "[test_iterate_reverse.cpp]" )
{
    DoubleLinkedList list;
    REQUIRE( list.size() == 0 );
    REQUIRE( list.empty() == true );
    
    std::vector<int> datos;
    auto collect = [&](TipoDato& dato) { datos.push_back(dato.num); };

    list.for_each(collect);
    REQUIRE( datos.size() == 0 );
    list.for_each_reverse(collect);
    REQUIRE( datos.size() == 0 );
}

TEST_CASE( "iterate_reverse - Pushing back - forward", "[test_iterate_reverse.cpp]" )
{
    DoubleLinkedList lista;
    std::vector<int> datos{1,2,3,4,5,6};
    for (auto it: datos) {
        lista.push_back(TipoDato{it});
    }
    REQUIRE( lista.empty() == false );
    REQUIRE( lista.size() == datos.size() );

    std::vector<int> collector;
    auto collect = [&](TipoDato& dato) { collector.push_back(dato.num); };
    lista.for_each(collect);
    REQUIRE( lista.size() == collector.size() );
    REQUIRE( collector == datos );
}

TEST_CASE( "iterate_reverse - Pushing back - backward", "[test_iterate_reverse.cpp]" )
{
    DoubleLinkedList lista;
    std::vector<int> datos{1,2,3,4,5,6};
    for (auto it: datos) {
        lista.push_back(TipoDato{it});
    }
    REQUIRE( lista.empty() == false );
    REQUIRE( lista.size() == datos.size() );

    std::vector<int> collector;
    auto collect = [&](TipoDato& dato) { collector.push_back(dato.num); };
    lista.for_each_reverse(collect);
    REQUIRE( lista.size() == collector.size() );
    std::reverse(collector.begin(), collector.end());
    REQUIRE( collector == datos );
}

TEST_CASE( "iterate_reverse - Pushing front - forward", "[test_iterate_reverse.cpp]" )
{
    DoubleLinkedList lista;
    std::vector<int> datos{1,2,3,4,5,6};
    for (auto it: datos) {
        lista.push_front(TipoDato{it});
    }
    REQUIRE( lista.empty() == false );
    REQUIRE( lista.size() == datos.size() );

    std::vector<int> collector;
    auto collect = [&](TipoDato& dato) { collector.push_back(dato.num); };
    lista.for_each(collect);
    REQUIRE( lista.size() == collector.size() );
    std::reverse(collector.begin(), collector.end());
    REQUIRE( collector == datos );
}

TEST_CASE( "iterate_reverse - Pushing front - backward", "[test_iterate_reverse.cpp]" )
{
    DoubleLinkedList lista;
    std::vector<int> datos{1,2,3,4,5,6};
    for (auto it: datos) {
        lista.push_front(TipoDato{it});
    }
    REQUIRE( lista.empty() == false );
    REQUIRE( lista.size() == datos.size() );

    std::vector<int> collector;
    auto collect = [&](TipoDato& dato) { collector.push_back(dato.num); };
    lista.for_each_reverse(collect);
    REQUIRE( lista.size() == collector.size() );
    REQUIRE( collector == datos );
}