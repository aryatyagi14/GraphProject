#include "scc.h"

#include <algorithm> 
#include <iostream>
#include <limits.h>
#include <fstream>

SCC::SCC() {

}

SCC::SCC(Graph g, string file_name) {
    g_ = g;
    file_name_ = file_name;

    map<int, int> disc; // stores when vertices were first discovered in traversal
    map<int, int> low; // stores the first vertex to be visited that can be reached
    stack<int> s; // stack for dfs
    map<int, bool> inStack; // stores whether vertices are currently in the stack
    
    // Initialize maps
    for (Vertex v : g.getVertices()) {
        disc[v.getId()] = INT_MAX;
        low[v.getId()] = INT_MAX;
        inStack[v.getId()] = false;
    }

    for (Vertex v : g.getVertices()) {
        if (disc[v.getId()] == INT_MAX)
            helper(v, disc, low, s, inStack);
    }

}

void SCC::helper(Vertex u, map<int, int>& disc, map<int, int>& low, stack<int>& s, map<int, bool>& inStack) {
    int vertexId = u.getId();
    static int timer = 0; // static to keep previous value for each recursive call
    static std::ofstream file(file_name_);
    disc[vertexId] = low[vertexId] = ++timer;
    s.push(vertexId);
    inStack[vertexId] = true;

    for (Vertex* v : g_.getAdjacentVertices(u)) {
        int adjId = v->getId();
        if (disc[adjId] == INT_MAX) {
            helper(*v, disc, low, s, inStack);
            low[vertexId] = std::min(low[vertexId], low[adjId]);
        } else if (inStack[v->getId()]) {
            low[vertexId] = std::min(low[vertexId], disc[adjId]);
        }
    }

    int printId = 0;
    if (low[vertexId] == disc[vertexId]) {
        set<int> group;
        while (s.top() != vertexId) {
            printId = s.top();
            group.insert(printId);
            file << printId << " ";
            inStack[printId] = false;
            s.pop();
        }
        printId = s.top();
        group.insert(printId);
        file << printId << "\n";
        inStack[printId] = false;
        s.pop();
        groups_.insert(group);
    }
}

set<set<int>> SCC::getGroups() {
    return groups_;
}