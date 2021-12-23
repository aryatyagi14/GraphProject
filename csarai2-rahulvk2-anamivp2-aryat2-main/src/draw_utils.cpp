#include "draw_utils.h"
#include <math.h>
#include <vector>
#include <iostream>

using namespace cs225;

void draw::drawEdge(Edge edge, size_t sqrtNumVertices, PNG & graph) {
    size_t width = graph.width();
    size_t spacing = width / sqrtNumVertices;
    size_t border = 10;
    double x1 = ((edge.getFrom() % sqrtNumVertices) * spacing) + border; // x-coord of the vertex
    double y1 = (((edge.getFrom() - (edge.getFrom() % sqrtNumVertices)) / sqrtNumVertices) * spacing) + border; // y-coord of the vertex
    
    double x2 = ((edge.getTo() % sqrtNumVertices) * spacing) + border; // x-coord of the vertex
    double y2 = (((edge.getTo() - (edge.getTo() % sqrtNumVertices)) / sqrtNumVertices) * spacing) + border; // y-coord of the vertex
    
    drawLine(edge.getWeight(), x1, y1, x2, y2, graph);
}

void draw::drawVertex(Vertex vertex, size_t sqrtNumVertices, size_t degree, PNG & graph) {
    size_t width = graph.width();
    size_t spacing = width / sqrtNumVertices;
    size_t border = 10;
    size_t x = ((vertex.getId() % sqrtNumVertices) * spacing) + border;          // x-coord of the vertex
    size_t y = (((vertex.getId() - (vertex.getId() % sqrtNumVertices)) / sqrtNumVertices) * spacing) + border;    // y-coord of the vertex
    
    
    double radius = (degree / sqrtNumVertices) * (spacing / 2); // the radius of the vertex
    if (radius > (spacing / 2)) {
        radius = (spacing / 2);        // set the radius to maxRadius
    } else if (radius < 4) {
        radius = 4;                    // set the radius to minRadius
    }

    drawCircle(radius, x, y, graph, vertex.getTrustLevel());
}


void draw::drawCircle(double radius, size_t x, size_t y, PNG & graph, int trust_level) {
    int hue = 0;
    if (trust_level > 0)
        hue = 225 - trust_level / graph.width();
    else
        hue = 315 - trust_level / graph.width();

    for (double i = radius; i >= 0; i--) {
        for (double j = 0; j < 2*M_PI; j += 0.1) {
            size_t x1 = (i*cos(j) + x) > 0 ? (i*cos(j) + x) : 0;
            size_t y1 = (i*sin(j) + y) > 0 ? (i*sin(j) + y) : 0;
            y1 = y1 > graph.width() - 1 ? graph.width() - 1 : y1;
            HSLAPixel & pixel = graph.getPixel(x1, y1);
            pixel.h = hue;
            pixel.s = 0.5;
            pixel.l = 0.5;
            pixel.a = 1;
        }
    }
}

void draw::drawLine(int weight, size_t x1, size_t y1, size_t x2, size_t y2, PNG & graph) {
    int hue = 0; // red
    if (weight > 0)
        hue = 150; // green

    double slope = 0;
    if ((x2 - x1) != 0)
        slope = (y2 - y1)/(x2 - x1);
    else
        slope = 1000;

    for (size_t x = x1, y = y1; x <= x2 && y <= y2; x += 1, y += slope) {
        y = y > graph.width() - 1 ? graph.width() - 1 : y;
        HSLAPixel & pixel = graph.getPixel(x, y);
        pixel.h = hue;
        pixel.s = 0.5;
        pixel.l = 0.5;
        pixel.a = 1;
    } 
}


PNG draw::drawGraph(Graph g, size_t width) {
    PNG graph(width, width); // create square png of the graph

    vector<Edge> edges = g.getEdges();
    vector<Vertex> vertices = g.getVertices();

    size_t sqrtNumVertices = sqrt(vertices.size());
    
    for (size_t i = 0; i < vertices.size(); i++) {
        vertices[i].setTrustLevel(g.calculateTrustLevel(vertices[i]));
        drawVertex(vertices[i], sqrtNumVertices, (g.getAdjacentVertices(vertices[i])).size(), graph);
    }

    for (size_t i = 0; i < edges.size(); i++) {
        drawEdge(edges[i], sqrtNumVertices, graph);
    }

    return graph;
}
