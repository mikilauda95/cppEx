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

template <typename T, typename S> 
ostream& operator<<(ostream& os, const pair<T, S>& v) 
{ 
	os << "("; 
	os << v.first << ", " << v.second << ")"; 
	return os; 
} 

unsigned int search_next(unsigned int nextNode, PriorityQueue<QueueType, less<QueueType> >& Q){
	while (Q.Top().second.second != nextNode) {
		Q.PickMinPriority();
	}
	return Q.Top().second.first;
}

vector<unsigned int> GetPath(unsigned int start, unsigned int dest, PriorityQueue<QueueType, less<QueueType> > Q)
{
	vector<unsigned int> tmp;
	unsigned nextNode = dest;
	tmp.push_back(nextNode);
	while(nextNode != start){
		nextNode = search_next(nextNode, Q);
		tmp.push_back(nextNode);

		//Debug
		//std::cout << "DEBUG" << std::endl;
		//std::cout << nextNode << std::endl;
	}
	return tmp;
	
}
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


// Compute (if not computed) and return the shortest path between two vertices as a list of nodes
vector<unsigned int> Algo :: path(unsigned int start,unsigned int dest){
		return this->ShortPathList.back().second;	
}

// Compute (if not computed) and return path size (sum of the distances) between two vertices
unsigned int Algo :: path_size(unsigned int u,unsigned int w){
		return this->ShortPathSizes.back().second;	
}
