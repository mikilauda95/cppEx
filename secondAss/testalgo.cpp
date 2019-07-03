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
	Graph G(100, 5);
	G.PrintGraph();
	Algo A(G);
	A.path(0,1);

	
	return 0;
}
