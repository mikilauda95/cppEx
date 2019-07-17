#include "Mypair.h"
#include "prim.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int minpath;
	Graph G(80, 5, 10);
	G.PrintGraph();
	Prim P(G);
	minpath = P.CompMinSpanningTree();
	cout << "Minimum spanning tree distance is : "  << minpath << endl;

	return 0;
}
