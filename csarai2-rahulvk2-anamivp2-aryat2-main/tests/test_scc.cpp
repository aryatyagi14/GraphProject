#include "../src/cs225/catch/catch.hpp"
#include "../src/scc.h"
#include "../src/parsing_utils.h"
#include "../src/graph.h"
#include "../src/vertex.h"
#include "../src/edge.h"

#include <fstream>
#include <set>

using namespace parser;
using std::set;

Graph generateGraph() {
    vector<Vertex> vertices;
    vector<Edge> edges;
    readFile(vertices, edges, "tests/test-dataset.txt");
    Graph g(vertices, edges);
    return g;
}

TEST_CASE("SCC Correctly Identifies strongly connected components") {
    Graph g = generateGraph();
    SCC scc(g, "tests/test-scc.txt");
    set<set<int>> groups = scc.getGroups();
    set<int> strongest_group;
    for (set<int> s : groups)
        if (s.size() > strongest_group.size())
            strongest_group = s;
    REQUIRE(strongest_group.size() == 4);
    REQUIRE(strongest_group.count(23));
    REQUIRE(strongest_group.count(25));
    REQUIRE(strongest_group.count(20));
    REQUIRE(strongest_group.count(5));
}
