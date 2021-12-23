#include "src/parsing_utils.h"
#include "src/vertex.h"
#include "src/edge.h"
#include "src/vertex.h"
#include "src/graph.h"
#include "src/dfs.h"
#include "src/draw_utils.h"
#include "src/scc.h"

#include "src/cs225/PNG.h"

#include <vector>
#include <iostream>

using namespace parser;
using namespace draw;
using namespace cs225;
using std::vector;

int main() {
    vector<Vertex> vertices;
    vector<Edge> edges;
    // Add file path string as third parameter to change dataset
    readFile(vertices, edges);
    // Create graph object
    Graph g(vertices, edges);
    // Add param for number of nodes/edges to display
    PNG graph = drawGraph(g, 10000);
    // Can change png file path 
    graph.writeToFile("Epinions.png");
    DFS dfs(g);
    // Add file path string as second parameter to change destination file
    SCC scc(g);
}