#include "graph.h"

Graph::Graph() {

}

Graph::Graph(vector<Vertex> vertices, vector<Edge> edges) {
    vertices_ = vertices;
    edges_ = edges;

    for (int i = 0; i < (int) edges_.size(); i++) {
        adj_map_[edges_[i].getFrom()].push_back(&edges_[i]);
        adj_map_[edges_[i].getTo()].push_back(&edges_[i]);
    }
}

vector<Vertex>& Graph::getVertices() {
    return vertices_;   // all of the vertices in the graph

}
        
vector<Edge>& Graph::getEdges() {
    return edges_;  // all of the edges in the graph
}
        
vector<Edge*> Graph::getIncidentEdges(Vertex vertex) {
    return adj_map_[vertex.getId()];
}

vector<Vertex*> Graph::getAdjacentVertices(Vertex v) {
    vector<Edge*> incidentEdges = getIncidentEdges(v);
    vector<Vertex*> adjacentVertices;
    for (Edge* e : incidentEdges) {
        if (e->getFrom() == v.getId()) {
            int adjId = e->getTo();
            adjacentVertices.push_back(&vertices_[adjId]);
        }
    }
    return adjacentVertices;
}

Edge& Graph::getEdge(Vertex from, Vertex to) {
    for (Edge* e : adj_map_[from.getId()]) {
        if (e->getTo() == to.getId())
            return *e;
    }
    return edges_[0];
}

int Graph::calculateTrustLevel(Vertex v) {
    vector<Edge*> incidentEdges = adj_map_[v.getId()];
    int trustLevel = 0;
    for (Edge* e : incidentEdges)
        if (e->getTo() == v.getId())
            trustLevel += e->getWeight();
    return trustLevel;
}
        