#include "prim.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
Prim :: Prim(Graph G) : G(G){

}

unsigned int Prim :: CompMinSpanningTree(unsigned int start, unsigned int dest){
	unsigned int tmpValue;
	vector<unsigned int> adiacents;
	
	//useless to use a priority queue here
	PriorityQueue<unsigned int> ExploredNodes;
	PriorityQueue<PrimQueueType> OpenSet;
	PrimQueueType tmpNode;
	PrimQueueType NextNode;

	NextNode.first = 0;
	NextNode.second = start;
	ExploredNodes.Insert(start);

	while (ExploredNodes.Size() != G.GetNumNodes()) {

		adiacents = G.GetAdiacents(NextNode.second);
		for (int i = 0; i < adiacents.size(); ++i) {
			tmpValue = G.GetEdgeValue(NextNode.second, adiacents[i]);
			OpenSet.Insert(make_pair(tmpValue, adiacents[i]));
		}
		
		//Compute the next node to analyze
		do {
			tmpNode = OpenSet.Top();
			OpenSet.PickMinPriority();
		} while (ExploredNodes.Contains(tmpNode.second));

		NextNode = tmpNode;
		ExploredNodes.Insert(NextNode.second);
	}

}
