#include "src/Graph.h"
#include "src/pagerank.h"
#include "src/dijkstras.h"
#include <iostream>
#include <string>
#include <stdlib.h>




int main() {
    Graph graph = Graph();
    std::vector<Vertex>& vertices = graph.getVertices();
    
    std::vector<int> dists = graph.BFS(vertices[0].name_);

    std::cout << "Printing BFS result based on first alphabetical vertex." << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << dists[i];
    }
    std::cout << std::endl;
    std::cout << "Printing Expected output" << std::endl;
    std::cout << "0-1-1-1-1-133333325634333435-12433544334-13-142234354456642455553533242-14-133433-143-13343-134-1-1333232424334-1344" << std::endl;
    
    dijkstras d = dijkstras(graph, vertices[0], vertices[10]);
    std::vector<string> big_d = d.dijkstrasAlg();
    std::cout << "Printing Dijkstra's Pathway from First Vertex to Eleventh Vertex." << std::endl;
    for (int i = 0; i < (int) big_d.size(); i++) {
        std::cout << big_d[i] << " ";
    }
    std::cout << std::endl;

    pagerank rank = pagerank();
    rank.createTrans();
    rank.readPageRank();
    std::cout << "Writing PageRank Pathway from Retina to United_States into searchFile.txt" << std::endl;
    rank.pageSearch(std::string("Retina"), std::string("United_States"));

    return 0;
    
}
