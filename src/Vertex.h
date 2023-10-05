#pragma once
#include "./Edge.h"
#include <string>



class Vertex {
    public:
    Vertex();
    Vertex(std::string name);
    //~Vertex();
    std::string name_;
    Edge* head_;
    Edge* tail_;
    bool equals(Vertex v2);
    private:
};