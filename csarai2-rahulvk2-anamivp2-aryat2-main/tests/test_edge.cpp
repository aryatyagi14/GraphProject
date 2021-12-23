#include "../src/cs225/catch/catch.hpp"
#include "../src/edge.h"


TEST_CASE("Test Edge Constructor/Set-Up") {
    SECTION("Check edge is not null & Test Edge empty constructor") {
        Edge e;
        REQUIRE_NOTHROW(e.getFrom());
    }

    SECTION("Check Edge constructor that takes in from, to, and weight") {
        Edge e = Edge(1, 2, 1);
        REQUIRE(e.getFrom() == 1);
        REQUIRE(e.getTo() == 2);
        REQUIRE(e.getWeight() == 1);
    }
}

TEST_CASE("Test Setters in Edge Class") {
    Edge e = Edge();
    
    SECTION("Check setFrom() sets the correct from vertex") {
        e.setFrom(1);
        REQUIRE(e.getFrom() == 1);
    }

    SECTION("Check setTo() sets the correct to vertex") {
        e.setTo(2);
        REQUIRE(e.getTo() == 2);
    }

    SECTION("Check setWeight() sets the correct edge weight") {
        e.setWeight(1);
        REQUIRE(e.getWeight() == 1);
    }

    SECTION("Check setLabel() sets the correct edge label") {
        e.setLabel("first");
        REQUIRE(e.getLabel() == "first");
    }
}

TEST_CASE("Test Getters in Edge Class") {
    Edge e = Edge(1, 2, 1);
    e.setLabel("first");

    SECTION("Check getFrom() retrieves the correct from vertex") {
        REQUIRE(e.getFrom() == 1);
    }

    SECTION("Check getTo() retrieves the correct to vertex") {
        REQUIRE(e.getTo() == 2);
    }

    SECTION("Check getWeight() retrieves the edge weight") {
        REQUIRE(e.getWeight() == 1);
    }

    SECTION("Check getLabel() retrieves the correct vertex label") {
        REQUIRE(e.getLabel() == "first");
    }

}