#pragma once

#include <string>

using std::string;

class Vertex {
    public:

        /**
         * Empty constructor for a vertex
        */ 
        Vertex();

        /**
         * Constructor for a vertex
         * @param id
        */ 
        Vertex(int id);

        // Getters

        /**
         * Returns the id of the vertex
         * @return id_ of the vertex
        */
        int getId();

        /**
         * Returns the label of the vertex
         * @return label_ of the vertex
        */
        string getLabel();

        /**
         * Returns the trust level of the vertex which is represented by the color of the vertex
         * @return trust_level_ of the vertex
        */
        int getTrustLevel();

        // Setters
        
        /**
         * Sets the id of the vertex
         * @param id the vertex's id
        */
        void setId(int id);
        
        /**
         * Sets the label of the vertex
         * @param label the vertex's label
        */
        void setLabel(string label);

        /**
         * Sets the trust level (or color) of the vertex 
         * @param trust_level the vertex's trust level
        */
        void setTrustLevel(int trust_level);
    
    private:
        int id_;        // the vertex id
        string label_;  // the vertex label
        int trust_level_;     // the color of the vertex
};