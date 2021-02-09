
#include <catch2/catch.hpp>

#include "palindrome.h"

SCENARIO( "Check corner cases", "[test_palindrome.cpp]" )
{
    REQUIRE( is_palindrome("") == true );
    REQUIRE( is_palindrome("A") == true );
    REQUIRE( is_palindrome("AA") == true );
}

SCENARIO( "Check a single word", "[test_palindrome.cpp]" )
{
    REQUIRE( is_palindrome("ana") == true );
    REQUIRE( is_palindrome("anna") == true );
    REQUIRE( is_palindrome("amadaladama") == true );

    REQUIRE( is_palindrome("cualquiercosa") == false );
    REQUIRE( is_palindrome("cualquiercos") == false );
}

SCENARIO( "Check with blanks", "[test_palindrome.cpp]" )
{
    REQUIRE( is_palindrome("amad a la dama") == true );
    REQUIRE( is_palindrome("ana lava lana") == true );

    REQUIRE( is_palindrome("ana no lava lana") == false );
}
