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
	openSet.Insert(0, start);
	pairtype nextNode;
	unsigned int Cost, Node;
	nextNode.first = 0;
	nextNode.second = start;
	while (1) {
		closeSet.Insert(nextNode.first, nextNode.second);
		if (nextNode.second == dest && closeSet.Contains(dest)){
			cout << nextNode.first << endl;
			break;
		}
		cout << "Close set is now : " << endl;
		closeSet.PrintQueue();
		adiacents = G.GetAdiacents(nextNode.second);
		G.PrintAdiacents(nextNode.second);
		cout << nextNode.first << " " << nextNode.second << endl;
		for (int i = 0; i < adiacents.size(); ++i) {
			Node = adiacents[i];
			Cost = nextNode.first + G.GetEdgeValue(Node, nextNode.second);
			openSet.Insert(Cost, Node);
		}
		cout << "Open set is now : " << endl;
		openSet.PrintQueue();
		openSet.PickMinPriority();
		nextNode = openSet.Top();
	}
	vector<unsigned int> tmp;
	return tmp;
}


Algo :: ~Algo(){

}


// Compute (if not computed) and return the shortest path between two vertices as a list of nodes
vector<unsigned int> Algo :: path(unsigned int start,unsigned int dest){
		return ComputeShortestPath(start, dest);	
}

// Compute (if not computed) and return path size (sum of the distances) between two vertices
void path_size(unsigned int u,unsigned int w){

}



