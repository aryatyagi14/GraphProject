#pragma once

#include "graph.h"
#include "vertex.h"

class DFS {
    public:
        DFS();
        DFS(Graph & g);
    private:
        void helper(Graph & g, Vertex & v);
};
