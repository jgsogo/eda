
#include <catch2/catch.hpp>

#include "Queue.h"


TEST_CASE( "Queue - ctor")
{
    Queue q;
    REQUIRE( q.size() == 0);
    REQUIRE( q.empty() );
}

TEST_CASE( "Persona - operator==")
{

}
