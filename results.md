
# Results

## Inputs
* This project takes an input of tsv files representing our dataset, in the form of one file representing the articles, which are our vertices, and one file representing the links between them, which are our weighted, directed, edges.
* Depending on the Algorithm used, the project will take more inputs.
* For the BFS traversal, it takes an input of a string representing the initial node to traverse from.
* For the Dijkstra's algorithm, it takes two string inputs, one representing the starting node, and another representing the ending node of the search.
* For the PageRank algorithm, it takes two string inputs, one representing the initial node, and another representing the ending node.

## Outputs
* Our project has five executables, main, BFS, dijkstra, pagerank, and test.
* Our main executable gives responses based on a given set of inputs to each algorithm.
* Our test executable contains unit tests and responds based on whether the algorithms act as expected.
* Our BFS algorithm will do two things, it will return a vector of distances from the starting node in terms of number of edges, with -1 representing that it is impossible to reach a specific vertex from the inputted start. It will additionally label each traversed edge as either discovery or cross.
* The Dijkstra's algorithm returns a vector of strings, which represents the pathway from the input starting vertex to the input ending vertex.
* The PageRank algorithm has two outputs. The first, and primary output, is the PageRank vector, which is held within the pageranks.txt file. That vector represents the weights applied to each vertex by the PageRank algorithm. The second is the search algorithm, which inputs a vector of each file visited, if it is able to traverse through highly-ranked articles to the ending article.

## Discoveries
* One discovery made with the underlying structure and executables of this project was the complexity of Makefiles. Sincere appreciation to office hours staff for the assistance.
* We discovered the effects of group work on a coding project. For many of us, this was our first group coding project. Managing github was an endeavor, but due to github branching, was made manageable.
* It was interesting to us that Dijkstra's algorithm doesn't apply any bearing to minimizing the number of vertexes in the path it selects.
* The effect of ews on system performance and simplicity was quite large, as we ran into issues with compiler and include paths due to struggles with ews.
* In the course of implementing PageRank, we found that the multiplication of matrices does not scale well, and power calculations in the process of multiplying large-scale matrices do not scale well for runtime.
* One solution attempted was multithreading, which was unsuccessful as the compiler did not support it, and thus was abandoned.
* We also found the PageRank is not deterministic, as it is not designed to find the fastest route, but rather to visit the most popular pages. Thus, the algorithm will sometimes not find a path, even when one exists.