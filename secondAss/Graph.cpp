#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include <vector>

#include "Graph.h"
using namespace std;

typedef vector<vector<unsigned int> > matrix;

// Void Constructor
// Graph implemented as an edge matrix
// Default constructor generates a random matrix based on the parameters passed
Graph :: Graph(float D, unsigned int N, unsigned int MaxRange) : Density(D), NumNodes(N), MaxRange(MaxRange){
	if (D > 100) {
		return;
	}


	matrix Mat(NumNodes, vector<unsigned int>(NumNodes));



	for (int i = 0; i < NumNodes; ++i) {
		for (int j = i; j < NumNodes; ++j) {
			if (j==i) {
				Mat[i][j] = 0;
			}
			else{
				if((rand()%100) < Density) {
					Mat[i][j] = Mat[j][i] = (rand()%MaxRange) + 1;
				}
			}
		}	
	}
	EdgeMatrix = Mat;
}

Graph :: Graph(const char* filepath){

	string line;
	unsigned int i, j, Cost, tmp;

	fstream fp(filepath);
	if (!fp) {
		std::cout << "Error when opening the file" << std::endl;
		exit(1);
	}

	fp >> NumNodes;
	// Debug
	//cout << NumNodes << endl;
	
	matrix Mat(NumNodes, vector<unsigned int>(NumNodes));
	while (fp >> tmp) {
		i = tmp;
		fp >> j;
		fp >> Cost;
		Mat[i][j] = Mat[j][i] = Cost;

		//Debug
		//std::cout << i << j << Cost << std::endl;
	}


	EdgeMatrix = Mat;
	

	//while(getline(fp, line)){
		//std::cout << line << std::endl;

		//stringstream parser(line);
		//parser >> i;
		//parser >> j;
		//parser >> Cost;

		//Mat[i][j] = Mat[j][i] = Cost;

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
		if (EdgeMatrix[i][NodeNum] > 0) {
			if (i != NodeNum) {
				tmp.push_back(i);
			}
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
