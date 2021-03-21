
#include <catch2/catch.hpp>

#include "Police.h"


TEST_CASE("Police - empty dnis") {
    Persona p0{"name0", "dni0", 0};
    Persona p1{"name1", "dni1", 1};
    Persona p2{"name2", "dni2", 0};
    Persona p3{"name3", "dni3", 0};

    Queue q;
    q.push(p0);
    q.push(p1);
    q.push(p2);
    q.push(p3);

    std::vector<std::string> dnis;
    auto q2 = police_raid(q, dnis);

    REQUIRE( q2.size() == 4);
    REQUIRE( q2.front() == p0);
    q2.pop();
    REQUIRE( q2.front() == p1);
    q2.pop();
    REQUIRE( q2.front() == p2);
    q2.pop();
    REQUIRE( q2.front() == p3);
}

TEST_CASE("Police - empty queue") {
    Queue q;
    std::vector<std::string> dnis{"dni1", "dni2"};
    auto q2 = police_raid(q, dnis);
    REQUIRE( q2.size() == 0);
}

TEST_CASE("Police - nobody found") {
    Persona p0{"name0", "dni0", 0};
    Persona p1{"name1", "dni1", 1};
    Persona p2{"name2", "dni2", 0};
    Persona p3{"name3", "dni3", 0};

    Queue q;
    q.push(p0);
    q.push(p1);
    q.push(p2);
    q.push(p3);

    std::vector<std::string> dnis{"no1", "no2"};
    auto q2 = police_raid(q, dnis);
    REQUIRE( q2.size() == 4);
}

TEST_CASE("Police - found") {
    Persona p0{"name0", "dni0", 0};
    Persona p1{"name1", "dni1", 1};
    Persona p2{"name2", "dni2", 0};
    Persona p3{"name3", "dni3", 0};

    Queue q;
    q.push(p0);
    q.push(p1);
    q.push(p2);
    q.push(p3);

    std::vector<std::string> dnis{"dni0", "dni3"};
    auto q2 = police_raid(q, dnis);
    REQUIRE( q2.size() == 2);
    REQUIRE( q2.front() == p1);
    q2.pop();
    REQUIRE( q2.front() == p2);
}
