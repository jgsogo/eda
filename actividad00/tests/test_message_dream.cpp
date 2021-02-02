
#include <catch2/catch.hpp>

#include "message_dream.h"

SCENARIO( "Check single letter arguments", "[test_message_dream.cpp]" )
{
    REQUIRE( message_dream("A", 0) == "A" );
    REQUIRE( message_dream("A", 1) == "AAA" );
    REQUIRE( message_dream("A", 2) == "AAAAAAAAA" );
    REQUIRE( message_dream("A", 3) == "AAAAAAAAAAAAAAAAAAAAAAAAAAA" );
}

SCENARIO( "Check a word", "[test_message_dream.cpp]" )
{
    REQUIRE( message_dream("hi!", 0) == "hi!" );
    REQUIRE( message_dream("hi!", 1) == "hhhiii!!!" );
    REQUIRE( message_dream("hi!", 2) == "hhhhhhhhhiiiiiiiii!!!!!!!!!" );
}

SCENARIO( "Check a phrase", "[test_message_dream.cpp]" )
{
    REQUIRE( message_dream("Soy Ana", 0) == "Soy Ana" );
    REQUIRE( message_dream("Soy Ana", 1) == "SSSoooyyy AAAnnnaaa" );
}
