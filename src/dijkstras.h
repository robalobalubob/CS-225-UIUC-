#pragma once
#include "./Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

using namespace std;

class dijkstras {
    public:
        dijkstras();
        dijkstras(Graph graph, Vertex head, Vertex tail);
        vector<string> dijkstrasAlg();


    private:
        Graph graph_;
        Vertex head_;
        Vertex tail_;


};
