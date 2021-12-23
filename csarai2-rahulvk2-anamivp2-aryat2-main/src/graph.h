#pragma once 

#include <vector>
#include <map>

#include "vertex.h"
#include "edge.h"

using std::vector;
using std::map;

class Graph {
    public:
        /**
         * Empty Constructor
         */
        Graph();
        
        /**
         * Custom constructor.
         * @param vertices
         * @param edges
         */
        Graph(vector<Vertex> vertices, vector<Edge> edges);
        
        // Getters
        vector<Vertex>& getVertices();
        vector<Edge>& getEdges();
        
        /**
         * Return incident edges of specified vertex.
         * @param vertex
         * @return vector of incident edges
         */
        vector<Edge*> getIncidentEdges(Vertex vertex);

        /**
         * Returns adjacent vertices to specified vertex.
         * @param vertex
         * @return vector of references to adjacent vertices
         */
        vector<Vertex*> getAdjacentVertices(Vertex vertex);

        /**
         * Return pointer to edge with specified from and to vertices.
         * @param from
         * @param to
         * @return edge pointer
         */
        Edge& getEdge(Vertex from, Vertex to);

        /**
         * Return trust level of passed in vertex as an integer.
         * @param v vertex
         * @return integer representing trust level (sum of weights of in-edges)
         */
        int calculateTrustLevel(Vertex v);

    private:
        vector<Vertex> vertices_;       // vector of all of the vertices in the graph
        vector<Edge> edges_;            // vector of all of the edges in the graph

        // maintain adjacency list
        map<int, vector<Edge*>> adj_map_;
};