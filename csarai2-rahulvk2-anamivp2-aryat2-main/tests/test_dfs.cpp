#include "../src/cs225/catch/catch.hpp"
#include "../src/dfs.h"
#include "../src/parsing_utils.h"
#include "../src/graph.h"
#include "../src/vertex.h"
#include "../src/edge.h"

#include <iostream>

using namespace parser;
using namespace Catch::Matchers;

Graph createGraph() {
    vector<Vertex> vertices;
    vector<Edge> edges;
    readFile(vertices, edges, "tests/test-dataset.txt");
    Graph g(vertices, edges);
    return g;
}

TEST_CASE("DFS visits all vertices and edges") {
    Graph g = createGraph();
    DFS dfs(g);
    SECTION("DFS visits all vertices") {
        for (Vertex v : g.getVertices()) {
            REQUIRE(v.getLabel() == "VISITED");
        }
    }
    SECTION("DFS visits all edges") {
        for (Edge e : g.getEdges()) {
            REQUIRE_THAT(e.getLabel(), Equals("DISCOVERY") || Equals("BACK"));
        }
    }
}