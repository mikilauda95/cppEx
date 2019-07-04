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
	PriorityQueue<QueueType> openSet;
	PriorityQueue<QueueType> closeSetPaths;
	PriorityQueue<unsigned int> closeSet;
	vector<unsigned int> adiacents;
	QueueType nextNode;
	unsigned int Cost, Node;
	nextNode.first = 0;
	nextNode.second.first = start;
	nextNode.second.second = start;
	openSet.Insert(nextNode);
	while (1) {
		closeSetPaths.Insert(openSet.Top());
		closeSet.Insert(openSet.Top().second.second);
		if (nextNode.second.second == dest && closeSet.Contains(dest)){
			cout << nextNode.first << endl;
			break;
		}
		cout << "Close set is now : " << endl;
		closeSet.PrintQueue();
		adiacents = G.GetAdiacents(nextNode.second.second);
		G.PrintAdiacents(nextNode.second.second);
		//cout << nextNode.first << " " << nextNode.second << endl;
		for (int i = 0; i < adiacents.size(); ++i) {
			Node = adiacents[i];
			Cost = nextNode.first + G.GetEdgeValue(Node, nextNode.second.second);
			openSet.Insert( make_pair(Cost, make_pair(nextNode.second.second, Node)));
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



