#pragma once
#include "vertex.h"
#include <string>

using std::string;

class Edge {
    public:

        /**
         * Empty constructor for an edge
        */
        Edge();

        /**
         * Constructor for an edge.
         * @param to, from, and weight of the edge
        */
        Edge(int from, int to, int weight);

        /**
         * Returns the from vertex of the edge
         * @return from_ the vertex the edge is from
        */
        int getFrom();

        /**
         * Returns the to vertex of the edge
         * @return to_ the vertex the edge goes to
        */
        int getTo();
        
        /**
         * Returns the weight of the edge
         * @return weight_ of the vertex
        */
        int getWeight();
        
        /**
         * Returns the label of the vertex
         * @return label_ of the vertex
        */
        string getLabel();
        
        /**
         * Sets the from vertex of the edge
         * @param from the vertex the edge is from
        */
        void setFrom(int from);

        /**
         * Sets the to vertex of the edge
         * @param to the vertex the edge goes to
        */
        void setTo(int to);

        /**
         * Sets the weight of the edge
         * @param weight of the vertex
        */
        void setWeight(int weight);
        
        /**
         * Sets the label of the edge
         * @param label of the edge
        */
        void setLabel(string label);


    private:
        int from_;      // the vertex the edge originates from
        int to_;        // the vertex the edge goes to
        int weight_;    // the weight of the edge
        string label_;  // the edge label
};