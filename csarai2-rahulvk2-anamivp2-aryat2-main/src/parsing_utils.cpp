#include "parsing_utils.h"
#include <fstream>
#include <set>

bool parser::readFile(vector<Vertex>& vertices, vector<Edge>& edges, string file_name) {
    std::ifstream file(file_name);
    string line;
    std::set<int> uniqueNodes;
    
    // Read lines of input file
	while (getline(file, line)) {
        // Skips lines that are comments
        if (line[0] == '#') {
            continue;
        }
        
        // Split lines by space
        string space_delimiter = "	";
        vector<string> parts;
        size_t pos = 0;
        
        while ((pos = line.find(space_delimiter)) != string::npos) {
            parts.push_back(line.substr(0, pos));
            line.erase(0, pos + space_delimiter.length());
        }
        
        parts.push_back(line.substr(0, pos));
        // Convert to integers
        int from = std::stoi(parts[0]);
        int to = std::stoi(parts[1]);
        int weight = std::stoi(parts[2]);

        // No self loops (simple graph)
        if (from != to) {
            // Create an edge with the nodes
            Edge e(from, to, weight);
            // Add edge to vector of edges
            edges.push_back(e);
        }
        // Add nodes to set of nodes
        uniqueNodes.insert(from);
        uniqueNodes.insert(to);
	}
    
    // Add nodes from set to vector of vertices
    for (int node : uniqueNodes) {
        Vertex v(node);
        vertices.push_back(v);
    }
    
    return true;
}