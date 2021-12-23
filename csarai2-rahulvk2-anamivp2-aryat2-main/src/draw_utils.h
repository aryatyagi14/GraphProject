#pragma once
#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include "cs225/PNG.h"

#include <string>

using std::string;

using namespace cs225;

namespace draw {
    /**
     * Returns PNG of graph.
     * @param g the graph
     * @param width the width of the PNG
     */
    PNG drawGraph(Graph g, size_t width = 500);

    /**
     * Draws edge onto png.
     * Green for positive, red for negative
     * @param edge the edge being drawn
     * @param sqrtNumVertices the square root of the number of vertices rounded
     * @param graph a reference to the PNG of the graph
     */
    void drawEdge(Edge edge, size_t sqrtNumVertices, PNG & graph);

    /**
     * Draws vertex onto png.
     * @param vertex the vertex being drawn
     * @param sqrtNumVertices the square root of the number of vertices rounded
     * @param graph a reference to the PNG of the graph
     */ 
    void drawVertex(Vertex vertex, size_t sqrtNumVertices, size_t degree, PNG & graph);

    // Helper methods to draw shapes
    void drawCircle(double radius, size_t x, size_t y, PNG & graph, int trust_level);
    void drawLine(int weight, size_t x1, size_t y1, size_t x2, size_t y2, PNG & graph);

}
// namespace draw
