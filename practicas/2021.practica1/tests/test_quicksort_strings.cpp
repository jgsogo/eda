
#include <catch2/catch.hpp>

#include "practica1.h"


TEST_CASE( "void quicksort_strings(std::vector<std::string>& values); -- dummy cases")
{
    std::vector<std::string> empty;
    quicksort_strings(empty);
    REQUIRE( empty == std::vector<std::string>{} );

    std::vector<std::string> single{"single string"};
    quicksort_strings(single);
    REQUIRE( single == std::vector<std::string>{"single string"} );
}

TEST_CASE( "void quicksort_strings(std::vector<std::string>& values);")
{
    std::vector<std::string> values{"aaa", "b", "aa", "ab", "a"};
    quicksort_strings(values);
    REQUIRE( values == std::vector<std::string>{"a", "b", "aa", "ab", "aaa"} );
}
