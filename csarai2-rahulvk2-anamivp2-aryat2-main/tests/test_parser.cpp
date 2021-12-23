#include "../src/cs225/catch/catch.hpp"
#include "../src/parsing_utils.h"
#include "../src/vertex.h"
#include "../src/edge.h"

#include <vector>

using namespace parser;

vector<Vertex> vertices;
vector<Edge> edges;

TEST_CASE("Read File into vectors") {
    readFile(vertices, edges, "tests/test-dataset.txt");
    REQUIRE(vertices.size() == 26);
    REQUIRE(edges.size() == 25);
}