
## Leading Question

* The goal of this project is to minimize the amount of time taken navigating from one random wikipedia page to another random wikipedia page through the enclusive use of the embed hyperlinks on the wikipedia pages, colloquially known as a wikipedia speedrun, when done in a race setting.
* A successful project would include a terminal-based search function, which would take inputs of two wikipedia article URLs, and return a list representing the article links which would minimize vertical scrolling to connect the start and end point.

## Dataset Acquisition and Processing

* The data set we are using is the Stanford Large Network Dataset Collection using the wikispeedia navigation paths. 
* Such data set is publicly available, at the link underneath this bullet point, in the form of .tsv files, which can be directly interacted with in the form of the STL fstream functions.
* http://snap.stanford.edu/data/wikispeedia.html
* The sections to focus on are the articles.tsv file, which contains the list of articles which will make up our vertices, and the links.tsv file, which comprises our directed edges.
* In the case of any errors, particularly in the realm of edge names which do not match vertices, those edges can either be ignored in the coding process or directly fixed by editing the files.
* Additionally, the edge weights will be representing the relative of the links to each other on the page. e.g. The nth link on the page would receive edge weight n. 

## Graph Algorithms

* The graph traversal will be BFS. Such a traversal will take an input of a starting node, and return a minimum spanning tree, representing the shortest routes to every other node from a specific node. An estimated big O runtime for this algorithm would be O(V + E), as it would need to check every edge and vertex.
* The graph algorithms will be Dijkstra's Algorithm and PageRank Algorithm.
* Dijkstra's Algorithm would take in a starting node and an ending node, and return a list of edges representing the fastest path from the start to the end, as defined in the leading question. An estimated big O runtime for this algorithm would be O((V+E)log(V)), as determined by the internet.
* PageRank would take in our created graph, and assign a ranking to each article representing the relative importance of each article within the set. It would then retern a map of nodes to their effective rank, informing of which articles would be optimal to start or end at. An estimated big O runtime for this algorithm would be O(n+m), as one has to touch every node once, and every edge twice, resulting in a runtime bound of O(n+m).

## Timeline
* 11/20 - Figure out how to process the data and generate a graph.
* 11/27 - Implement Dijkstra's Algorithm.
* 12/8 - Implement PageRank
* 12/10 - Buffer Time for when something inevitably goes wrong.
* 12/12 - Have the presentation and report done.
* 12/13 - Proofread everything and finalize the project.