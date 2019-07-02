#include "Algo.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

Algo :: Algo(Graph G):G(G){
	//Implement some checks
}

vector<unsigned int> Algo :: ComputeShortestPath(unsigned int start,unsigned int dest){
	PriorityQueue closeSet, openSet;
	vector<unsigned int> adiacents;
	closeSet.Insert(0, start);
	pairtype nextNode;
	unsigned int Cost, Node;
	nextNode.first = 0;
	nextNode.second = start;
	while (1) {
		closeSet.Insert(nextNode.first, nextNode.second);
		adiacents = G.GetAdiacents(nextNode.second);
		for (int i = 0; i < adiacents.size(); ++i) {
			Node = adiacents[i];
			Cost = nextNode.first + nextNode.first;
			openSet.Insert(Cost, Node);
		}
		closeSet.PickMinPriority();
		nextNode = openSet.Top();
		//nextNode = Step(nextNode);
		if (nextNode.second == dest && closeSet.Contains(dest)){
			break;
		}
	}
}



