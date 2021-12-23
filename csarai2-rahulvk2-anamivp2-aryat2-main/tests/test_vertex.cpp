#include "../src/cs225/catch/catch.hpp"
#include "../src/vertex.h"


TEST_CASE("Test Vertex Constructor/Set-Up") {
    SECTION("Check vertex is not null & Test Empty Constructor") {
        Vertex v;
        REQUIRE_NOTHROW(v.getId());
    }

    SECTION("Check Vertex constructor that takes in an id") {
        Vertex v = Vertex(10);
        REQUIRE(v.getId() == 10);
    }
}

TEST_CASE("Test Setters in Vertex Class") {
    Vertex v = Vertex();
    
    SECTION("Check setId() sets the correct vertex id") {
        v.setId(1);
        REQUIRE(v.getId() == 1);
    }

    SECTION("Check setLabel() sets the correct vertex label") {
        v.setLabel("first");
        REQUIRE(v.getLabel() == "first");
    }

    SECTION("Check setTrustLevel() sets the correct vertex trust level") {
        v.setTrustLevel(250);
        REQUIRE(v.getTrustLevel() == 250);
    }
}

TEST_CASE("Test Getters in Vertex Class") {
    Vertex v = Vertex();
    v.setId(1);
    v.setLabel("first");
    v.setTrustLevel(250);

    SECTION("Check getId() retrieves the correct vertex id") {
        REQUIRE(v.getId() == 1);
    }
    SECTION("Check getLabel() retrieves the correct vertex label") {
        REQUIRE(v.getLabel() == "first");
    }

    SECTION("Check getTrustLevel() retrieves the correct vertex trust level") {
        REQUIRE(v.getTrustLevel() == 250);
    }
}