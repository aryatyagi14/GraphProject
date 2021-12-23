#include "../src/cs225/catch/catch.hpp"
#include "../src/draw_utils.h"
#include "../src/parsing_utils.h"
#include "../src/graph.h"
#include "../src/vertex.h"
#include "../src/edge.h"

using namespace cs225;
using namespace parser;
using namespace draw;

Graph makeGraph() {
    vector<Vertex> vertices;
    vector<Edge> edges;
    readFile(vertices, edges, "tests/test-dataset.txt");
    Graph g(vertices, edges);
    return g;
}

TEST_CASE("Draw works") {
    Graph g = makeGraph();
    PNG graph = drawGraph(g);
    REQUIRE_NOTHROW(graph.writeToFile("tests/test-graph.png"));
}