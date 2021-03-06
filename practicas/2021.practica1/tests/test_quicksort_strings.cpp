
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "void quicksort_strings(std::vector<std::string>& values);")
{
    std::vector<std::string> values;
    quicksort_strings(values);

    REQUIRE( false );
}
