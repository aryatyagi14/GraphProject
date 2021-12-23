#pragma once

#include <vector>
#include <string>

#include "vertex.h"
#include "edge.h"

using std::vector;
using std::string;

namespace parser {

    bool readFile(vector<Vertex>& vertices, vector<Edge>& edges, string file_name = "soc-sign-epinions.txt");

} // namespace parser