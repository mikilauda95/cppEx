#include "Mypair.h"
#include "Algo.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

Algo :: Algo(Graph G):G(G){
	//Implement some checks
}

// Overload the pair type to print it easily
template <typename T, typename S> 
ostream& operator<<(ostream& os, const pair<T, S>& v) 
{ 
	os << "("; 
	os << v.first << ", " << v.second << ")"; 
	return os; 
} 

// Auxiliary function used by GetPath
unsigned int search_next(unsigned int nextNode, PriorityQueue<QueueType, less<QueueType> >& Q){
	// Keep scrolling the list until the nextNode is the destination node of another path in the close set
	while (Q.Top().second.second != nextNode) {
		Q.PickMinPriority();
	}
	return Q.Top().second.first;
}

//Compute the list of nodes of the shortest Path from the Priority queue of the Close Set
vector<unsigned int> GetPath(unsigned int start, unsigned int dest, PriorityQueue<QueueType, less<QueueType> > Q)
{
	// Starting from the destination, chain the destinations and start point to get the Path
	vector<unsigned int> tmp;
	unsigned nextNode = dest;
	tmp.push_back(nextNode);
	// stop when we arrive at the start node
	while(nextNode != start){
		nextNode = search_next(nextNode, Q);
		tmp.push_back(nextNode);

		//Debug
		//std::cout << "DEBUG" << std::endl;
		//std::cout << nextNode << std::endl;
	}
	return tmp;
	
}
//
//Compute the shortest Path and update the data members containing sizes and path
void Algo :: ComputeShortestPath(unsigned int start,unsigned int dest){
	
	//Debug
	//cout << "Computing shortest path from node " << start << " to node " << "dest " << dest << endl;
	
	PriorityQueue<QueueType, greater<QueueType> > openSet;
	PriorityQueue<QueueType, less<QueueType> > closeSetPaths;
	PriorityQueue<Mypair, greater<Mypair> > closeSet;
	vector<unsigned int> adiacents;
	QueueType nextNode;
	unsigned int Cost, Node;
	nextNode.first = 0;
	nextNode.second.first = start;
	nextNode.second.second = start;
	openSet.Insert(nextNode);
	while (1) {
		//Debug
		//cout << "Analyzed node is " << nextNode.first << " " << nextNode.second << endl;

		if (!closeSet.Contains(make_pair(openSet.Top().first, openSet.Top().second.second))) {
			closeSetPaths.Insert(openSet.Top());
			closeSet.Insert(make_pair(openSet.Top().first, openSet.Top().second.second));
		}

		//Debug
		//cout << "Close set is now : " << endl;
		//closeSetPaths.PrintQueue();
		//closeSet.PrintQueue();

		if (nextNode.second.second == dest && closeSet.Contains(make_pair(0, dest))){
			//Debug
			//cout << nextNode.first << endl;
			break;
		}
		adiacents = G.GetAdiacents(nextNode.second.second);

		//Debug
		//G.PrintAdiacents(nextNode.second.second);
		
		for (int i = 0; i < adiacents.size(); ++i) {
			Node = adiacents[i];
			Cost = nextNode.first + G.GetEdgeValue(Node, nextNode.second.second);
			openSet.DecrPriority( make_pair(Cost, make_pair(nextNode.second.second, Node)));
		}
		//Debug
		//cout << "Open set is now : " << endl;
		//openSet.PrintQueue();
		
		openSet.PickMinPriority();
		nextNode = openSet.Top();
	}


	pair<unsigned int, vector<unsigned int> > tmp;

	// Set distance
	tmp.first = nextNode.first;
	// Set path vector
	tmp.second = GetPath(start, dest, closeSetPaths);

	// Add to the local data structures
	ShortPathList.push_back(make_pair(make_pair(start, dest), tmp.second));
	ShortPathSizes.push_back(make_pair(make_pair(start, dest), tmp.first));
}


Algo :: ~Algo(){

}


//Return the last shortest path between two vertices as a list of nodes
vector<unsigned int> Algo :: path(unsigned int start,unsigned int dest){
		return this->ShortPathList.back().second;	
}

//Return the last shortest path size computed (sum of the distances) between two vertices
unsigned int Algo :: path_size(unsigned int u,unsigned int w){
		return this->ShortPathSizes.back().second;	
}
