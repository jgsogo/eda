
#include <catch2/catch.hpp>

#include "Queue.h"


TEST_CASE( "Queue - empty")
{
    Queue q;
    REQUIRE( q.size() == 0);
    REQUIRE( q.empty() );
}

TEST_CASE( "Queue - one element")
{
    Persona p1{"name1", "dni1", 1};

    Queue q;
    q.push(p1);
    REQUIRE( q.size() == 1);
    REQUIRE( !q.empty() );
    REQUIRE (q.front() == p1);
    REQUIRE (q.back() == p1);

    q.pop();
    REQUIRE( q.size() == 0);
    REQUIRE( q.empty() );
}

TEST_CASE( "Queue - several elements")
{
    Persona p1{"name1", "dni1", 1};
    Persona p2{"name2", "dni2", 0};
    Persona p3{"name3", "dni3", 0};

    Queue q;
    q.push(p1);
    q.push(p2);
    q.push(Persona{"other", "other", 0});
    q.push(Persona{"other", "other", 0});
    q.push(p3);
    REQUIRE( q.size() == 5);
    REQUIRE( !q.empty() );
    REQUIRE (q.front() == p1);
    REQUIRE (q.back() == p3);

    q.pop();
    REQUIRE( q.size() == 4);
    REQUIRE (q.front() == p2);
    REQUIRE (q.back() == p3);

    q.pop();
    q.pop();
    q.pop();
    REQUIRE( q.size() == 1);
    REQUIRE (q.front() == p3);
    REQUIRE (q.back() == p3);

    q.pop();
    REQUIRE( q.size() == 0);
    REQUIRE( q.empty() );
}

TEST_CASE( "Queue - sneak_in - empty/not found")
{
    Persona p1{"name1", "dni1", 1};
    Persona p2{"name2", "dni2", 0};
    Persona p3{"name3", "dni3", 0};

    Queue q;
    Queue friends;
    friends.push(p1);
    friends.push(p2);
    friends.push(p3);

    q.sneak_in(p1, friends);
    REQUIRE( q.size() == 0);
    REQUIRE( q.empty() );

    q.push(p3);
    q.sneak_in(p1, friends);
    REQUIRE( q.size() == 1);
}

TEST_CASE( "Queue - sneak_in - found first")
{
    Persona p0{"name0", "dni0", 1};
    Persona p1{"name1", "dni1", 1};
    Persona p2{"name2", "dni2", 0};
    Persona p3{"name3", "dni3", 0};

    Queue q;
    q.push(p0);
    q.push(p1);

    Queue friends;
    friends.push(p2);
    friends.push(p3);

    q.sneak_in(p0, friends);
    REQUIRE( q.size() == 4);

    REQUIRE( q.front() == p0);
    q.pop();
    REQUIRE( q.front() == p2);
    q.pop();
    REQUIRE( q.front() == p3);
    q.pop();
    REQUIRE( q.front() == p1);
}

TEST_CASE( "Queue - sneak_in - found last")
{
    Persona p0{"name0", "dni0", 1};
    Persona p1{"name1", "dni1", 1};
    Persona p2{"name2", "dni2", 0};
    Persona p3{"name3", "dni3", 0};

    Queue q;
    q.push(p0);
    q.push(p1);

    Queue friends;
    friends.push(p2);
    friends.push(p3);

    q.sneak_in(p1, friends);
    REQUIRE( q.size() == 4);

    REQUIRE( q.front() == p0);
    q.pop();
    REQUIRE( q.front() == p1);
    q.pop();
    REQUIRE( q.front() == p2);
    q.pop();
    REQUIRE( q.front() == p3);
}
