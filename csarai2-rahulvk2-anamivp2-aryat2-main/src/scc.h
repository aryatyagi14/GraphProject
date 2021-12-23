#pragma once

#include "graph.h"
#include "vertex.h"

#include <map>
#include <stack>
#include <string>
#include <set>

using std::map;
using std::stack;
using std::string;
using std::set;

class SCC {
    public:
        SCC();
        SCC(Graph g, string file_name = "scc.txt");
        set<set<int>> getGroups();
    private:
        void helper(Vertex u, map<int, int>& disc, map<int, int>& low, stack<int>& s, map<int, bool>& inStack);
        Graph g_;
        string file_name_;
        set<set<int>> groups_;
};