#ifndef PRIM_H
#define PRIM_H

#include "Graph.h"
#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

typedef pair<unsigned int, unsigned int> PrimQueueType;

class Prim
{
private:
	
	Graph G;


public:
	Prim(Graph G);
	virtual ~Prim();
	unsigned int CompMinSpanningTree(void);
};



#endif /* PRIM_H */
