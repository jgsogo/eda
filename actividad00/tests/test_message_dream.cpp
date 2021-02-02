
#include <catch2/catch.hpp>

#include "message_dream.h"

SCENARIO( "Verify no argument returns Hello World", "[test_Hello.cpp]" )
{
    REQUIRE( message_dream("Hello", 0) == "Hello World" );
}
