
# ReadMe

## Structure
* Our source files are contained within a src folder. This includes: the general graph structure, the file containing Dijkstra's Algorithm, and the file containing the PageRank algorithm.
* Our data input files, as well as our data output files, are contained within a folder labeled data. This includes the articles file, the links files, and the output PageRank file.
* Our executables and our markdown files, are not contained within a folder, for ease of usage.
* Our test suite is contained within a folder labeled tests.
* The video presentation is hosted by zoom cloud, a link to which is in the video.txt file.

## Using this Project

### Main
* The main executable of this project can be run in two steps.
* Step 1: Type "make" in the terminal.
* Step 2: Type "./main" in the terminal.
* This will print out in the terminal a set of results based on inputs supplies by us, with expected values.

### BFS
* The BFS executable of this project can be run in two steps.
* Step 1: Type "make BFS" in the terminal.
* Step 2: Type "./BFS 'input vertex'" in the terminal. That 'input vertex' is the name of whatever article will be the starting node for the BFS traversal.
* This will print out in the terminal a string of 100 numbers, which represent the distance from the input vertex to the first 100 vertices (sorted alphabetically) in terms of the number of edges, with -1 representing that a vertex is unreachable from the input.

### Dijkstra's
* The Dijkstra's executable of this project can be run in two steps.
* Step 1: Type "make dijkstra" in the terminal.
* Step 2: Type "./dijkstra 'starting vertex' 'ending vertex'" in the terminal. That 'starting vertex' is the name of whatever article will be the starting node for the dijksra search, with the 'ending vertex' being the ending node for the search.
* This will print out in the terminal a list of article names, representing the pathway from the starting vertex to the ending vertex, which will be the pathway which minimizes weight, determined as the amount of scrolling, to click on the links.

### PageRank
* The PageRank executable of this project can be run in two steps.
* Step 1: Type "make pagerank" in the terminal.
* Step 2: Type "./pagerank 'starting vertex' 'ending vertex' 'number'" in the terminal. That 'starting vertex' is the name of whatever article will be the starting node for the pagerank search, with the 'ending vertex' being the ending node for the search. The third parameter, 'number' is either 0 or 1, with 0 being to use the already created pagerank.txt file, and 1 being to recreate the file using our methods.
* As a note, creating the txt file takes a significantly larger runtime.
* This will generate a file called searchFile.txt, which contains a list of vertices visited by the PageRank algorithm. It also will, if the third parameter is a 1, generate a pageranks.txt file representing the weights. Should a pathway not be found, it will print, "destination not found".

## Testing

* The tests can be run in two steps.
* Step 1: Type "make" in the terminal.
* Step 2: Type "./main" in the terminal.
* As a description of our test suite, our suite contains tests for BFS, testing the algorithm against it's expected output for the first two vertices. (sorted alphabetically)
* It also contains tests for Dijkstra's, with testing the expected output against given start and end vertices.
* For PageRank testing, we test the calculations of the matrices, and we test the pathway visited against given inputs.
