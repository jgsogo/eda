
#include <catch2/catch.hpp>

#include "practica1.h"
#include <iostream>

TEST_CASE( "int invertir(int num);" )
{
    CHECK( invertir(1) == 1 );
    CHECK( invertir(2) == 2 );
    bool r25 = invertir(25) == 52;
    std::cout << ">" << invertir(1024) << std::endl;
    std::cout << ">" << r25 << std::endl;
    CHECK( r25 );
    CHECK( invertir(1024) == 4201 );
}
