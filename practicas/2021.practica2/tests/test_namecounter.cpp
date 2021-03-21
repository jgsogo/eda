
#include <catch2/catch.hpp>

#include "NameCounter.h"


TEST_CASE("NameCounter - ElementListaSimple") {
    ElementListaSimple e1{NameCount{23, "manuel"}};
    REQUIRE( e1.next == nullptr);
    REQUIRE( e1.dato.repeats == 23);
    REQUIRE( e1.dato.name == "manuel");
}

TEST_CASE("NameCounter -- all different") {
    NameCounter c;
    c.add_name("n1");
    c.add_name("n2");
    c.add_name("n3");
    c.add_name("n4");

    std::vector<std::string> names;
    c.for_each([&](const NameCount& name){
        names.push_back(name.name);
        REQUIRE( name.repeats == 1);
    });

    std::sort(names.begin(), names.end());
    REQUIRE( names == std::vector<std::string>{"n1", "n2", "n3", "n4"});
}

TEST_CASE("NameCounter -- two equal") {
    NameCounter c;
    c.add_name("n1");
    c.add_name("n2");
    c.add_name("n1");
    c.add_name("n4");

    std::vector<std::string> names;
    c.for_each([&](const NameCount& name){
        names.push_back(name.name);
    });

    std::sort(names.begin(), names.end());
    REQUIRE( names == std::vector<std::string>{"n1", "n2", "n4"});
}

TEST_CASE("NameCounter -- sort method") {
    NameCounter c1;
    c1.sort();  // Check it doesn't raise

    NameCounter c2;
    c2.add_name("n3");
    c2.sort();  // Check it doesn't raise
}

TEST_CASE("NameCounter -- sorted") {
    NameCounter c;
    c.add_name("n3");
    c.add_name("n1");
    c.add_name("n2");
    c.add_name("n1");
    c.add_name("n2");
    c.add_name("n2");
    c.add_name("n4");
    c.sort();

    std::vector<NameCount> names;
    c.for_each([&](const NameCount& name){
        names.push_back(name);
    });

    REQUIRE( names.size() == 4);
    REQUIRE( names[0].repeats == 3);
    REQUIRE( names[0].name == "n2");
    REQUIRE( names[1].repeats == 2);
    REQUIRE( names[1].name == "n1");
    REQUIRE( names[2].repeats == 1);
    REQUIRE( (names[2].name == "n3" || names[2].name == "n4") );
    REQUIRE( names[3].repeats == 1);
    REQUIRE( (names[2].name == "n3" || names[2].name == "n4") );
}
