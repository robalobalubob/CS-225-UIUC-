#include "./dijkstras.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <queue>
#include <functional>
#include <stack>

using namespace std;

/* 
Dijkstra's algorithm will recieve an instance of our graph, edge weights, a starting article, and an ending article. 
It will return a vector of strings containing the articles names in the order that produces the the shortest path between the start and end articles.
*/


/*
PSUEDO CODE:
for each vertex V in G
        dist[V] <- infinite
        prev[V] <- NULL
        If V != S, add V to Priority Queue Q
    dist[S] <- 0
    
    while Q IS NOT EMPTY
        U <- Extract MIN from Q
        for each unvisited neighbour V of U
            temperoryDist <- dist[U] + edgeWeight(U, V)
            if temperoryDist < dist[V]
                dist[V] <- temperoryDist
                prev[V] <- U
    return dist[], prev[]

*/

dijkstras::dijkstras() {

}

dijkstras::dijkstras(Graph graph, Vertex head, Vertex tail){
    graph_ = graph;
    head_ = head;
    tail_ = tail;
}

vector<string> dijkstras::dijkstrasAlg(){
    
    vector<Vertex> vertices = graph_.getVertices();
    vector<int> distance = vector<int>(vertices.size(), INT_MAX);
    vector<int> parents = vector<int>(vertices.size(), -1); //Think disjoint sets, the starting vertex is the root, 
                                                                //and each vertex gets set unioned as we visit them.

    int headIdx = graph_.lookup_table.find(head_.name_)->second;
    int tailIdx = graph_.lookup_table.find(tail_.name_)->second;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    if (headIdx == tailIdx) {
        vector<string> toReturn = vector<string>();
        toReturn.emplace_back(vertices[headIdx].name_);
        return toReturn;
    }

    distance[headIdx] = 0;
    pq.push(make_pair(0,headIdx));

    stack<string> previous;

    while (!pq.empty()) {
        pair<int,int> curr = pq.top(); //curr->first = distance, curr->second = index of vertex
        pq.pop();
        Edge* currEdge = vertices[curr.second].head_;
        while(currEdge != NULL) {
            //Determine which vertex points to.
            int destination_vertex = graph_.lookup_table.find(currEdge->name_)->second; //index of destination in vertices
            //Determine new distance
            int temp_dist = curr.first + currEdge->weight_;
            //if new distance less than dist already there
            if (temp_dist < distance[destination_vertex]) {
                //alter dist in distance vector
                //push to pq
                //add current vertex as parent
                distance[destination_vertex] = temp_dist;
                pq.push(make_pair(temp_dist,destination_vertex));
                parents[destination_vertex] = curr.second;
            }

            
            //otherwise do nothing
            //then increment currEdge
            currEdge = currEdge->next_;
        }
    }

    vector<string> toReturn = vector<string>();
    if (distance[tailIdx] == INT_MAX) { //If we can't get the the end node from the start, just write that, and return out.
        toReturn.push_back("No Path Found");
        return toReturn;
    }

    stack<int> s;
    int currIdx = tailIdx;

    while(true) { //Next, start at the tail, and push each index onto the stack.
                    //Think like mp mazes backtracing.
        if (parents[currIdx] == -1) { //When we reach the root, we're done.
            break;
        }
        s.push(parents[currIdx]);
        currIdx = parents[currIdx];
    }

    while (!s.empty()) { //Then pop every index off the stack and add their names to the vector.
        int curr = s.top();
        s.pop();
        toReturn.push_back(vertices[curr].name_);
    }
    toReturn.push_back(vertices[tailIdx].name_); //This stack method doesn't put the tail on the stack, so do it.
    return toReturn;
}
