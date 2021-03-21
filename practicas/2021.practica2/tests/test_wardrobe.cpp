
#include <catch2/catch.hpp>

#include "Wardrobe.h"


TEST_CASE( "WardrobeElement")
{
    WardrobeElement wb{"owner"};
    REQUIRE( wb.owner == "owner" );
    REQUIRE( wb.next == nullptr );
}

TEST_CASE( "Wardrobe")
{
    Wardrobe wb;
    REQUIRE( wb.size() == 0);
    REQUIRE( wb.empty() );

    wb.push("e1");
    REQUIRE( wb.size() == 1);
    REQUIRE( !wb.empty() );
    REQUIRE( wb.top() == "e1" );

    wb.push("e2");
    REQUIRE( wb.size() == 2);
    REQUIRE( !wb.empty() );
    REQUIRE( wb.top() == "e2" );

    wb.pop();
    REQUIRE( wb.size() == 1);
    REQUIRE( !wb.empty() );
    REQUIRE( wb.top() == "e1" );

    wb.pop();
    REQUIRE( wb.size() == 0);
    REQUIRE( wb.empty() );
}

TEST_CASE("Wardrobe - function") {
    Persona p0{"name0", "dni0", 0};
    Persona p1{"name1", "dni1", 1};
    Persona p2{"name2", "dni2", 0};
    Persona p3{"name3", "dni3", 0};

    Queue q;
    q.push(p0);
    q.push(p1);
    q.push(p2);
    q.push(p3);

    Wardrobe w1, w0;
    wardrobe(q, w0, w1);

    REQUIRE( w0.size() == 3);
    REQUIRE( w0.top() == "name3");
    w0.pop();
    REQUIRE( w0.top() == "name2");
    w0.pop();
    REQUIRE( w0.top() == "name0");

    REQUIRE( w1.size() == 1);
    REQUIRE( w1.top() == "name1");
}
