

EXENAME = main

OBJS = Graph.o Vertex.o Edge.o pagerank.o main.o dijkstras.o

TEST = tests
CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm 
# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)


main.o: main.cpp src/Graph.h src/Vertex.h src/Edge.h src/pagerank.h src/dijkstras.h
	$(CXX) $(CXXFLAGS) main.cpp

Graph.o: src/Graph.cpp src/Graph.h src/Vertex.h src/Edge.h
	$(CXX) $(CXXFLAGS) src/Graph.cpp

Vertex.o: src/Vertex.cpp src/Vertex.h src/Edge.h
	$(CXX) $(CXXFLAGS) src/Vertex.cpp

Edge.o: src/Edge.cpp src/Edge.h
	$(CXX) $(CXXFLAGS) src/Edge.cpp

pagerank.o: src/pagerank.cpp src/pagerank.h
	$(CXX) $(CXXFLAGS) src/pagerank.cpp

dijkstras.o: src/dijkstras.cpp src/dijkstras.h
	$(CXX) $(CXXFLAGS) src/dijkstras.cpp

test: output_msg tests.o Graph.o Vertex.o Edge.o pagerank.o dijkstras.o
	$(LD) tests.o Graph.o Vertex.o Edge.o pagerank.o dijkstras.o $(LDFLAGS) -o test

tests.o: tests/tests.cpp tests/catch.hpp src/Graph.h src/Vertex.h src/Edge.h src/pagerank.h src/dijkstras.h
	$(CXX) $(CXXFLAGS) tests/tests.cpp

BFS: BFS.o Graph.o Vertex.o Edge.o
	$(LD) BFS.o Graph.o Vertex.o Edge.o $(LDFLAGS) -o BFS

BFS.o: BFS.cpp src/Graph.h src/Vertex.h src/Edge.h
	$(CXX) $(CXXFLAGS) BFS.cpp

dijkstra: Graph.o Vertex.o Edge.o dij.o dijkstras.o
	$(LD) Graph.o Vertex.o Edge.o dij.o dijkstras.o $(LDFLAGS) -o dijkstra

dij.o: dij.cpp src/Graph.h src/Vertex.h src/Edge.h src/dijkstras.h
	$(CXX) $(CXXFLAGS) dij.cpp

pagerank: Graph.o Vertex.o Edge.o pg.o pagerank.o
	$(LD) Graph.o Vertex.o Edge.o pg.o pagerank.o $(LDFLAGS) -o pagerank

pg.o: pg.cpp src/Graph.h src/Vertex.h src/Edge.h src/pagerank.h
	$(CXX) $(CXXFLAGS) pg.cpp

clean:
	-rm -f *.o $(EXENAME) test BFS dijkstra pagerank