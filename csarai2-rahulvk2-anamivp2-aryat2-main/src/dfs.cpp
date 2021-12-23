#include "dfs.h"
#include <stack>
#include <iostream>

using std::stack;

DFS::DFS() {
    
}

DFS::DFS(Graph& g) {
    for (Vertex& v : g.getVertices())
        v.setLabel("UNEXPLORED");
    for (Edge& e : g.getEdges())
        e.setLabel("UNEXPLORED");
    for (Vertex& v: g.getVertices())
        if (v.getLabel() == "UNEXPLORED")
            helper(g, v);
}

void DFS::helper(Graph & g, Vertex & v) {
    stack<Vertex> s;
    v.setLabel("VISITED");
    std::cout << v.getId() << std::endl;
    s.push(v);

    while(!s.empty()) {
        v = s.top();
        s.pop();
        // iterate through adjacent nodes
        for (Vertex* w : g.getAdjacentVertices(v)) {
            // get edge from v to w
            Edge& e = g.getEdge(v, *w);
            if (w->getLabel() == "UNEXPLORED") {
                e.setLabel("DISCOVERY");
                w->setLabel("VISITED");
                std::cout << w->getId() << std::endl;
                s.push(*w);
            }
            else if (e.getLabel() == "UNEXPLORED") {
                e.setLabel("BACK");
            }
        }
    }
}