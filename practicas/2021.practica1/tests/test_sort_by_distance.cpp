
#include <catch2/catch.hpp>

#include "practica1.h"

bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}


TEST_CASE( "void sort_by_distance(std::vector<Point>& values, float origin_x, float origin_y); -- dummy tests")
{
    std::vector<Point> empty;
    sort_by_distance(empty, 0.f, 0.f);
    REQUIRE(empty == std::vector<Point>{});

    std::vector<Point> single{Point{1, 2}};
    sort_by_distance(single, 0.f, 0.f);
    REQUIRE(single == std::vector<Point>{Point{1, 2}});
}

TEST_CASE( "void sort_by_distance(std::vector<Point>& values, float origin_x, float origin_y); -- origin(0, 0)")
{
    std::vector<Point> single{Point{0.5f, 10.f}, Point{1.f, 1.f}, Point{2.f, 2.f}};
    sort_by_distance(single, 0.f, 0.f);
    REQUIRE(single == std::vector<Point>{Point{1.f, 1.f}, Point{2.f, 2.f}, Point{0.5f, 10.f}});
}

TEST_CASE( "void sort_by_distance(std::vector<Point>& values, float origin_x, float origin_y); -- origin(0, 10)")
{
    std::vector<Point> single{Point{0.5f, 10.f}, Point{1.f, 1.f}, Point{2.f, 2.f}};
    sort_by_distance(single, 0.f, 10.f);
    REQUIRE(single == std::vector<Point>{Point{0.5f, 10.f}, Point{2.f, 2.f}, Point{1.f, 1.f}});
}

