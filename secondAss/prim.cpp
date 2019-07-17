#include "prim.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include <functional>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

// Overload the pair type to print it easily
template <typename T, typename S> 
ostream& operator<<(ostream& os, const pair<T, S>& v) 
{ 
	os << "("; 
	os << v.first << ", " << v.second << ")"; 
	return os; 
} 

//Void Constructor. Initializing only the graph
Prim :: Prim(Graph G) : G(G){

}


//Void Constructor. Initializing only the graph
Prim :: ~Prim(){

}

unsigned int Prim :: CompMinSpanningTree(void){
	unsigned int tmpValue;
	vector<unsigned int> adiacents;
	
	//useless to use a priority queue here
	//PriorityQueue<unsigned int> ExploredNodes;
	vector<unsigned int> ExploredNodes;
	PriorityQueue<PrimQueueType> OpenSet;
	PrimQueueType tmpNode;
	PrimQueueType NextNode;

	unsigned int distance = 0;
	NextNode.first = 0;
	NextNode.second = 0;
	ExploredNodes.push_back(0);

	// Keep looping until we cover all the nodes in the graph
	while (ExploredNodes.size() != G.GetNumNodes()) {

		//debug
		//std::cout << "Analyzing node " << NextNode << std::endl;
		//Compute the adiacents of the picked node and add them to the open set
		adiacents = G.GetAdiacents(NextNode.second);
		for (int i = 0; i < adiacents.size(); ++i) {
			tmpValue = G.GetEdgeValue(NextNode.second, adiacents[i]);
			OpenSet.Insert(make_pair(tmpValue, adiacents[i]));
		}

		//debug
		//OpenSet.PrintQueue();
		
		//Compute the next node to analyze
		//Stop when you find a node which has not been explored yet
		do {
			tmpNode = OpenSet.Top();
			OpenSet.PickMinPriority();
		} while (find(ExploredNodes.begin(), ExploredNodes.end(), tmpNode.second)!= ExploredNodes.end());

		// Update the next node, the explored node list and the distance
		NextNode = tmpNode;
		ExploredNodes.push_back(NextNode.second);
		distance += NextNode.first;
	}

	return distance;


}
