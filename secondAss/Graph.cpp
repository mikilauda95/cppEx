#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <vector>

#include "Graph.h"
using namespace std;


// Void Constructor
Graph :: Graph(float D, unsigned int N) : Density(D), NumNodes(N){
	if (D > 100) {
		return;
	}

	srand(time(NULL));

	typedef vector<vector<unsigned int> > matrix;
	matrix Mat(NumNodes, vector<unsigned int>(NumNodes));



	for (int i = 0; i < NumNodes; ++i) {
		for (int j = i; j < NumNodes; ++j) {
			if (j==i) {
				Mat[i][j] = 0;
			}
			else{
				if((rand()%100) < Density) {
					Mat[i][j] = Mat[j][i] = (rand()%50) + 1;
				}
			}
		}	
	}
	EdgeMatrix = Mat;

	//vector<unsigned int> Row;
	//for (int i = 0; i < NumNodes; ++i) {
	//Row.clear();
	//for (int j = 0; j < NumNodes; ++j) {
	//if (j!=i) {
	//if((rand()%100) < Density) {
	//Row.push_back(j);
	//}
	//}
	//}	
	//EdgeMatrix.push_back(Row);
	//}
}

// Copy Constructor
Graph :: Graph(const Graph& G){
	EdgeMatrix = G.EdgeMatrix;
	NumNodes = G.NumNodes;
	Density = G.Density;
}

// Destructor
Graph :: ~Graph(){

}

// AddNode()
// To be done later. For the moment fixed dimension.
//AddNode();

// RemoveNode()
// For the moment eliminating a node will simply correspond to zero its column and row
//RemoveNode(NodeNum);

// GetNumNodes()
// Return the number of nodes 
unsigned int Graph :: GetNumNodes(){
	return NumNodes;
}

// GetNumEdges()
// Return the number of edges of a graph (although it is an undirected graph, we are going to count each edge twice)
unsigned int Graph :: GetNumEdges(){
	unsigned int count = 0;
	for (int i = 0; i < NumNodes; ++i) {
		for (int j = 0; j < NumNodes; ++j) {
			if (EdgeMatrix[i][j] > 0) {
				count++;
			}
		}
	}
	return count;
}

// SetNodeValue
// Set the node value/name to a certain node 
void SetNodeValue(string NodeName, unsigned int NodeNum);


// AvPathLen()
// Compute Average Path Length for a node as the average of the distances to the adiacent nodes (edge > 0)
float Graph :: AvPathLen(unsigned int NodeNum){
	unsigned int count = 0;
	float acc = 0;
	for (int i = 0; i < NumNodes; ++i) {
		if (EdgeMatrix[NodeNum][i] > 0) {
			acc += EdgeMatrix[NodeNum][i];
			count++;
		}
	}
	return acc/count;
}

// PrintAvLen()
void Graph :: PrintAvPathLen(unsigned int NodeNum){
	cout << "AvpathLen = " << AvPathLen(NodeNum) << endl;
}

// GetAdiacents()
// Return a vector of all the adiacents node (edge > 0)
vector<unsigned int> Graph :: GetAdiacents(unsigned int NodeNum){
	vector<unsigned int> tmp;
	for (int i = 0; i < NumNodes; ++i) {
		if (EdgeMatrix[i][NodeNum] > 0 ) {
			tmp.push_back(i);
		}
	}
	return tmp;
}

// GetNodeNumEdges
// Return the number of edges > 0
unsigned int Graph :: GetNodeNumEdges(unsigned int NodeNum){
	unsigned int count = 0;
	for (int i = 0; i < NumNodes; ++i) {
		if (EdgeMatrix[i][NodeNum] > 0) {
			count++;
		}
	}
	return count;
}


// RemoveEdge
// Remove an Edge between two nodes (it does not check if it is there because it would simply set to zero an already zero value)
void Graph :: RemoveEdge(unsigned int NodeNum1, unsigned int NodeNum2){
	EdgeMatrix[NodeNum1][NodeNum2] = EdgeMatrix[NodeNum2][NodeNum1] = 0;
}

// GetEdgeValue
unsigned int Graph :: GetEdgeValue(unsigned int NodeNum1, unsigned int NodeNum2){
	return EdgeMatrix[NodeNum1][NodeNum2];

}

// SetEdge
void Graph :: SetEdge(unsigned int NodeNum1, unsigned int NodeNum2, unsigned int Value){
	EdgeMatrix[NodeNum1][NodeNum2] = Value;
	EdgeMatrix[NodeNum2][NodeNum1] = Value;
}

// AddEdge()
// Like SetEdge but it adds an edge only if there is no edge
void Graph :: AddEdge(unsigned int NodeNum1, unsigned int NodeNum2, unsigned int Value){
	if (EdgeMatrix[NodeNum1][NodeNum2] == 0) {
		SetEdge(NodeNum1, NodeNum2, Value);
	}
}

// PrintGraph
// Print the graph as an adjiacency list
void Graph :: PrintGraph(){
	for (int i = 0; i < EdgeMatrix.size(); ++i) {
		for (int j = 0; j < EdgeMatrix[i].size(); ++j) {
			cout << EdgeMatrix[i][j]<< ", ";
		}
		cout << endl;
	}
}

// PrintAdiacents
void Graph :: PrintAdiacents(unsigned int NodeNum){
	vector<unsigned int> adiacents = GetAdiacents(NodeNum);
	for (int i = 0; i < adiacents.size(); ++i) {
		cout <<"Node " << NodeNum << " is adiacent with " << adiacents[i] << endl;
	}
}

// Adiacent()
// Check if two nodes are adiacents
bool Graph :: Adiacent(unsigned int NodeNum1, unsigned int NodeNum2){
	if (EdgeMatrix[NodeNum1][NodeNum2] > 0) {
		return true;	
	}
}

// IsConnected()
// Return True if the graph is connected, False else
bool Graph :: IsConnected(){

}
