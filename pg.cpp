#include "src/Graph.h"
#include "src/pagerank.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>




int main(int argc, char * argv[]) {
    if (argc != 4) {
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
    if (strncmp(argv[3], "0",1) == 0) {
        pagerank rank = pagerank();
        rank.createTrans();
        rank.readPageRank();  
        int a = rank.pageSearch(vertices[graph.lookup_table.find(argv[1])->second].name_, vertices[graph.lookup_table.find(argv[2])->second].name_);
        if (a >= 0) {
            std::cout << "Writing PageRank Pathway from Retina to United_States into searchFile.txt" << std::endl;
        }
    } else if (strncmp(argv[3], "1",1) == 0) {
        pagerank rank = pagerank();
        rank.createTrans();
        rank.powerCalc();
        int a = rank.pageSearch(vertices[graph.lookup_table.find(argv[1])->second].name_, vertices[graph.lookup_table.find(argv[2])->second].name_);
        if (a >= 0) {
            std::cout << "Writing PageRank Pathway from Retina to United_States into searchFile.txt" << std::endl;
        }
    } else {
        std::cout << "Invalid Parameters Passed" << std::endl;
        return 0;
    }
    

    
    return 0;
    
}
