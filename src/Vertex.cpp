#include "./Vertex.h"
#include <iostream>

Vertex::Vertex() {
    head_ = NULL;
    tail_ = NULL;
}

Vertex::Vertex(std::string name) {
   // if (name_ == "Zulu") {
   //     std::cout << "Creating Vertex: " << name_ << std::endl;
   // }
    head_ = NULL;
    tail_ = NULL;
    name_ = name;
}
/*
Vertex::~Vertex() {
    if (name_ == "Zulu") {
        std::cout << "Deleting Vertex: " << name_ << std::endl;
    }
    if (head_ == NULL) {
        return;
    }
    delete head_;
    head_ = NULL;
    tail_ = NULL;
}
*/
bool Vertex::equals(Vertex v2){
    if(name_ == v2.name_){
        return true;
    }
    return false;
}