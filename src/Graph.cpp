#include "./Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <utility>

Graph::Graph() {
    std::ifstream read_file; // The filestream for the links with weights.
    std::ifstream vertex_file; // The filestream for the vertices.
    std::string vert; //This string holds the lines from the vertices file.
    std::string link; // This string holds the lines from the links with weights file.


    vertices = std::vector<Vertex>();
    lookup_table = std::unordered_map<std::string, int>();
    vertex_file.open("data/articles.tsv");
    read_file.open("data/links_with_weights.tsv");

    for (int i = 0; i < 12; i++) { //Bypasses the header on the vertex file.
        std::getline(vertex_file, vert);
    }

    int cnt = 0; //cnt keeps track of the vector index we are on.
    while (std::getline(vertex_file, vert)) { //Iterates through every vertex.
        lookup_table[vert] = cnt; //Put the key in the map of the name to the index.
        vertices.emplace_back(vert);
        cnt++;
    }

    int count = 0; //Keeps track of which vector we are on.
    while (std::getline(read_file, link)) { //Iterates through the links.

        std::string vertex; //Will hold the starting vertex of the link.
        std::string dest; //Will hold the destination of the link.
        std::string text_weight; //Holds the edge weight of the link in string form.
        int weight; //The edge weight in int form.

        int index = link.find("	"); //The location of the first space.
        vertex = link.substr(0, index); //Vertex now holds the name of the vertex.
        dest = link.substr(index); //Dest now holds, " <Destination Name> <Weight>"
        dest = dest.substr(1); //Dest now holds, "<Destination Name> <Weight>"

        int fir_index = dest.find(" "); //The position of the first space.
        int las_index = dest.find_first_not_of(" ", fir_index); //The position of the first thing which is not a space after the first space.

        text_weight = dest.substr(las_index); //Now holds, "<Weight>"
        dest = dest.substr(0, fir_index); //Now holds, "<Destination Name>"
        weight = std::stoi(text_weight); //Convert to int.

        Edge* edge = new Edge();
        edge->name_ = dest;
        edge->weight_ = weight;
        if (vertices[count].name_ == vertex) { //If the vertex count points to is the same as the start, do nothing.

        } else { //Otherwise, alter count to point at the correct vertex.
            count++;
        }
        edge->next_ = vertices[count].head_;
        vertices[count].head_ = edge;
        if (edge->next_ == NULL) {
            vertices[count].tail_ = edge;
        }
    }
}

std::vector<Vertex>& Graph::getVertices() {
    return vertices;
}

std::vector<int> Graph::BFS(std::string _string){

    Vertex& start = vertices[lookup_table.find(_string)->second]; //Converting name to vector object
    queue.push(start); //Push the starting vertex onto the queue
    dists = std::vector<int>(vertices.size(), -1); //Initialize the distances from the starting node as -1, to represent that they have not been visited
    int idx = lookup_table.find(start.name_)->second; //Get the index of the starting vertex.

    dists[idx] = 0;

    while(!queue.empty()){ //Iterate until empty queue
        
        Vertex curr_ = queue.front(); //retrieve the vertex at the front of the queue
        queue.pop();
        Edge* cedge = curr_.head_; //Get the first edge.

        while(cedge!=NULL){ //Iterate through each edge in the linked list.

            if(dists[lookup_table.find(cedge->name_)->second] == -1){ //If the vertex hasn't been visited yet,
                queue.push(edgeToVert(cedge)); //Put the vertex on the queue
                cedge->label_ = "discovery"; //Label the edge as discovery
                //Write the correct distance in the distance vector
                int par_dist = dists[lookup_table.find(curr_.name_)->second]; 
                int index = lookup_table.find(cedge->name_)->second;
                dists[index] = par_dist + 1;

            } else {
                cedge->label_ = "cross"; //Otherwise, label the edge as a cross edge.
            }

            cedge =  cedge->next_;
        }

    }

    return dists;
}

Graph::~Graph() {
    for (int i = 0; i < (int) vertices.size(); i++) {
        Edge* cedge = vertices[i].head_;
        delete cedge;
    }
}

Vertex& Graph::edgeToVert(Edge *e){
    auto index = lookup_table.find(e->name_);
    return vertices[index->second];
}

