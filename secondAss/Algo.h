#ifndef ALGO_H
#define ALGO_H

#include "Graph.h"
#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

typedef pair<unsigned int, pair<unsigned int, unsigned int> > pairtype;
typedef pair<unsigned int, unsigned int> StartDest;
class Algo
{
private:
	Graph G;
	PriorityQueue Q;
	vector<pair<StartDest, vector<unsigned int> > > ShortPathList; 

	vector<unsigned int> ComputeShortestPath(unsigned int start,unsigned int dest);
	int Step(unsigned int node);
	
public:
	
	// Construct the Algo class from the Graph on which the computation is done.
	Algo(Graph G);
	virtual ~Algo();

	// Compute (if not computed) and return the shortest path between two vertices as a list of nodes
	vector<unsigned int> path(unsigned int start,unsigned int dest);
	
	// Compute (if not computed) and return path size (sum of the distances) between two vertices
	void path_size(unsigned int u,unsigned int w);

};

#endif /* ALGO_H */
