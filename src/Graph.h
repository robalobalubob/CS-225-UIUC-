#pragma once
#include "./Vertex.h"
#include "./Edge.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using std::queue;
//using std::map;

class Graph {
    public:
    Graph(); // Basic constructor, to read in the links_with_weights file and generate the vertices vector.
    ~Graph();
    std::vector<Vertex>& getVertices(); // Returns a reference to the vertices vector.
    std::vector<int> BFS(std::string _string);
    std::unordered_map<std::string,int> lookup_table; //This maps the string name of the vertices to their location in the vertices vector.
    private:
        std::vector<Vertex> vertices; //Contains all the vertices in alphabetical order
        std::vector<int> dists;// = vector<int>(vertices.size());
        queue<Vertex> queue;
        
        Vertex& edgeToVert(Edge *e);
        
};