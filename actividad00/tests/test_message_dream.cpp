
#include <catch2/catch.hpp>

#include "message_dream.h"

SCENARIO( "Check single letter arguments", "[test_message_dream.cpp]" )
{
    REQUIRE( message_dream("A", 0) == "A" );
    REQUIRE( message_dream("A", 1) == "AA" );
    REQUIRE( message_dream("A", 2) == "AAAA" );
    REQUIRE( message_dream("A", 3) == "AAAAAAAA" );
}

SCENARIO( "Check a word", "[test_message_dream.cpp]" )
{
    REQUIRE( message_dream("hi!", 0) == "hi!" );
    REQUIRE( message_dream("hi!", 1) == "hhii!!" );
    REQUIRE( message_dream("hi!", 2) == "hhhhiiii!!!!" );
}
