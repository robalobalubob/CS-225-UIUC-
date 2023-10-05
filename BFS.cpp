#include "src/Graph.h"
#include <iostream>
#include <string>
#include <stdlib.h>


int main(int argc, char * argv[]) {
    
    if (argc != 2) {
        std::cout << "Invalid Parameters Passed" << std::endl;
        return 0;
    }

    Graph graph = Graph();

    if (graph.lookup_table.find(argv[1]) == graph.lookup_table.end()) {
        std::cout << "Invalid Parameters Passed" << std::endl;
        return 0;
    }

    std::vector<Vertex>& vertices = graph.getVertices();
    std::vector<int> dists = graph.BFS(vertices[graph.lookup_table.find(argv[1])->second].name_);

    std::cout << "Printing the first 100 distances in number of edges from the first node to each other node. -1 represents that" << std::endl;
    std::cout << "a node is impossible to reach from the first node. The nodes are sorted alphabetically." << std::endl;

    for (int i = 0; i < 100; i++) {
        std::cout << dists[i];
    }

    std::cout << std::endl;
    return 0;
    
}
