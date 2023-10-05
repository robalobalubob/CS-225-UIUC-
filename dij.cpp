#include "src/Graph.h"
#include "src/dijkstras.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>




int main(int argc, char * argv[]) {
    if (argc != 3) {
        std::cout << "Invalid Parameters Passed" << std::endl;
        return 0;
    }

    Graph graph = Graph();

    if (graph.lookup_table.find(argv[1]) == graph.lookup_table.end()) {
        std::cout << "Invalid Parameters Passed" << std::endl;
        return 0;
    }

    if (graph.lookup_table.find(argv[2]) == graph.lookup_table.end()) {
        std::cout << "Invalid Parameters Passed" << std::endl;
        return 0;
    }

    std::vector<Vertex>& vertices = graph.getVertices();
    int startIdx = graph.lookup_table.find(argv[1])->second;
    int endIdx = graph.lookup_table.find(argv[2])->second;
    
    dijkstras d = dijkstras(graph, vertices[startIdx], vertices[endIdx]);
    std::vector<string> dij = d.dijkstrasAlg();

    std::cout << "Printing Dijkstra's Pathway from First Vertex to Eleventh Vertex." << std::endl;
    for (int i = 0; i < (int) dij.size(); i++) {
        std::cout << dij[i] << " ";
    }
    std::cout << std::endl;

    
    return 0;
    
}
