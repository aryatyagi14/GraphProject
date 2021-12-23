#include "../src/cs225/catch/catch.hpp"
#include "../src/dfs.h"
#include "../src/parsing_utils.h"
#include "../src/graph.h"
#include "../src/vertex.h"
#include "../src/edge.h"

#include <iostream>

#include <vector>
#include <string>

using std::vector;
using std::string;

using namespace parser;
using namespace Catch::Matchers;

Graph createGraph(string file_name) {
    vector<Vertex> vertices;
    vector<Edge> edges;
    readFile(vertices, edges, file_name);
    Graph g(vertices, edges);
    return g;
}

TEST_CASE("Test Graph Constructor/Set-Up") {
    SECTION("Check graph edge is not null & Test the Graph empty constructor") {
        Graph g;
        REQUIRE_NOTHROW(g.getVertices());
    }

    SECTION("Check Edge constructor that takes in from, to, and weight") {
        vector<Vertex> vertices;
        vector<Edge> edges;
        Graph* g = new Graph(vertices, edges);
        
        REQUIRE(g != NULL);
        REQUIRE(g->getVertices().empty());
        REQUIRE(g->getEdges().empty());
    }
}

TEST_CASE("Test Getters in Graph Class") {
    Graph g = createGraph("tests/sample_graph.txt");

    SECTION("Check getVertices() retrieves the vector of vertices in the graph") {
        vector<Vertex> sample_vertices = {Vertex(0), Vertex(1), Vertex(2)};

        REQUIRE(g.getVertices().size() == sample_vertices.size());

        for (int i = 0; i < (int) sample_vertices.size(); i++) {
            REQUIRE(g.getVertices().at(i).getId() == sample_vertices.at(i).getId());
        }
    }

    SECTION("Check getEdges() retrieves the vector of edges in the graph") {
        Edge e1 = Edge(0, 1, -1);
        Edge e2 = Edge(1, 0, -1);
        Edge e3 = Edge(2, 1, 1);
        vector<Edge> sample_edges = {e1, e2, e3};

        REQUIRE(g.getEdges().size() == sample_edges.size());

        for (int i = 0; i < (int) sample_edges.size(); i++) {
            REQUIRE(g.getEdges().at(i).getFrom() == sample_edges.at(i).getFrom());
            REQUIRE(g.getEdges().at(i).getTo() == sample_edges.at(i).getTo());
            REQUIRE(g.getEdges().at(i).getWeight() == sample_edges.at(i).getWeight());
        }
    }

    SECTION("Check getIncidentEdges() retrieves the correct incident edge of the specified vertex") {
        Edge incident_1(0, 1, -1);
        Edge incident_2(2, 1, 1);
        Edge incident_3(1, 0, -1);

        // getting incident edges of vertex 1
        REQUIRE(g.getIncidentEdges(1)[0]->getWeight() == incident_1.getWeight());
        REQUIRE(g.getIncidentEdges(1)[0]->getFrom() == incident_1.getFrom());
        REQUIRE(g.getIncidentEdges(1)[2]->getWeight() == incident_2.getWeight());
        REQUIRE(g.getIncidentEdges(1)[1]->getFrom() == incident_3.getFrom());
    }

    SECTION("Check getAdjacentVertices() retrieves the correct adjacent vertices to the specified vertex") {
        // vertex 0
        Vertex v1(1);
        REQUIRE(g.getAdjacentVertices(0)[0]->getId() == v1.getId());

        // vertex 2
        REQUIRE(g.getAdjacentVertices(2)[0]->getId() == v1.getId());
    }

    SECTION("Check getEdge() retrieves a pointer to the edge with the given from and to vertices") {
        Edge e1(0, 1, -1);
        REQUIRE(g.getEdge(0, 1).getWeight() == e1.getWeight());

        Edge e2(1, 0, -1);
        REQUIRE(g.getEdge(1, 0).getWeight() == e2.getWeight());

        Edge e3(2, 1, 1);
        REQUIRE(g.getEdge(2, 1).getWeight() == e3.getWeight());
    }

}

TEST_CASE("Calculate Trust Level works") {
    Graph g = createGraph("tests/sample_graph.txt");
    REQUIRE(g.calculateTrustLevel(0) == -1);
    REQUIRE(g.calculateTrustLevel(1) == 0);
    REQUIRE(g.calculateTrustLevel(2) == 0);
}
