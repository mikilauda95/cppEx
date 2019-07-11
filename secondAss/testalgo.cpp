#include "Mypair.h"
#include "Algo.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int start, dest, size;
	start = 0;
	dest = 1;

	vector<unsigned int> path;
	Graph G(90, 10, 10000);
	G.PrintGraph();
	Algo A(G);
	A.ComputeShortestPath(start, dest);
	path = A.path(start, dest);
	size = A.path_size(start, dest);
	std::cout << "printing the path for start " << start << " and dest " << dest << std::endl;


	for (int i = 0; i < path.size(); ++i) {
		std::cout << path[i] << std::endl;
	}

	std::cout << "Size is " << size << std::endl;
	
	G.PrintGraph();

	return 0;
}
