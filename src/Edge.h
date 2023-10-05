#pragma once
#include <string>

class Edge {
    public:
    Edge();
    ~Edge();
    std::string name_;
    std::string label_;
    int weight_;
    Edge* next_;

    private:

};