#include "Mypair.h"
#include "Algo.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Program to compute the average shortest path for a series of Graphs
int main(int argc, char *argv[])
{
	const unsigned int NUM_GRAPHS = 10;
	const unsigned int GRAPH_SIZE = 10;
	const unsigned int GRAPH_DENS = 100;
	const unsigned int GRAPH_MAXR = 1000;

	unsigned int start, dest;

	//Initialize the seed used by rand function inside graph
	srand(time(NULL));
	
	
	for (int i = 0; i < NUM_GRAPHS; ++i) {
		//Generate a random graph
		Graph G(GRAPH_DENS, GRAPH_SIZE, GRAPH_MAXR);
		G.PrintGraph();
		Algo A(G);
		vector<unsigned int> sizes;
		for (start = 0; start < GRAPH_SIZE; start++) {
			for (dest = 0; dest < GRAPH_SIZE; ++dest) {
				if (start != dest){
					vector<unsigned int> path;
					//Compute the path
					A.ComputeShortestPath(start, dest);
					//Get the shortest path computed
					path = A.path(start, dest);
					//Get the size of the shortest path computed
					sizes.push_back(A.path_size(start, dest));
				}
			}
		}
		// Compute the average
		unsigned int acc = 0;
		float average;
		for (int i = 0; i < sizes.size(); ++i) {
			acc+=sizes[i];
		}


		average = ((float) acc) / sizes.size();
		std::cout << "Average Path Size is " << average << std::endl;
	}

	return 0;
}
