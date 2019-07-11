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

int main(int argc, char *argv[])
{
	const unsigned int NUM_GRAPHS = 10;
	const unsigned int GRAPH_SIZE = 10;
	const unsigned int GRAPH_DENS = 100;
	const unsigned int GRAPH_MAXR = 1000;

	unsigned int start, dest;

	srand(time(NULL));
	
	for (int i = 0; i < NUM_GRAPHS; ++i) {
		Graph G(GRAPH_DENS, GRAPH_SIZE, GRAPH_MAXR);
		G.PrintGraph();
		Algo A(G);
		vector<unsigned int> sizes;
		for (start = 0; start < GRAPH_SIZE; start++) {
			for (dest = 0; dest < GRAPH_SIZE; ++dest) {
				if (start != dest){
					vector<unsigned int> path;
					A.ComputeShortestPath(start, dest);
					path = A.path(start, dest);
					sizes.push_back(A.path_size(start, dest));
				}
			}
		}
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
