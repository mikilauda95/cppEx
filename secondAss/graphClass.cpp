#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <vector>

#include "graphClass.h"
using namespace std;


// Void Constructor
GraphClass :: GraphClass(float D, unsigned int N) : Density(D), NumNodes(N){
	srand(time(NULL));

	typedef vector<vector<unsigned int> > matrix;
	matrix Mat(NumNodes, vector<unsigned int>(NumNodes));

	for (int i = 0; i < NumNodes; ++i) {
		for (int j = 0; j < NumNodes; ++j) {
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
GraphClass :: GraphClass(const GraphClass& G){

}
// Destructor
GraphClass :: ~GraphClass(){

}

// AddNode()
// To be done later. For the moment fixed dimension.
//AddNode();

// RemoveNode()
// For the moment eliminating a node will simply correspond to zero its column and row
//RemoveNode(NodeNum);

// GetNodeValue
// Return the node value/name assigned (if it exist)
string GetNodeValue(unsigned int NodeNum);

// SetNodeValue
// Set the node value/name to a certain node 
void SetNodeValue(string NodeName, unsigned int NodeNum);

// GetAdiacents()
// Return a vector of all the adiacents node (edge > 0)
vector<int> GetAdiacents();

// GetNumEdges
// Return the number of edges > 0
unsigned int GetNumEdges(unsigned int NodeNum);


// RemoveEdge
// Remove an Edge between two nodes
void RemoveEdge(unsigned int NodeNum1, unsigned int NodeNum2);

// GetEdgeValue
unsigned int GetEdgeValue(unsigned int NodeNum);

// SetEdge
void SetEdge(unsigned int NodeNum1, unsigned int NodeNum2);

// PrintGraph
// Print the graph as an adjiacency list
void GraphClass::PrintGraph(){
	for (int i = 0; i < EdgeMatrix.size(); ++i) {
		for (int j = 0; j < EdgeMatrix[i].size(); ++j) {
			cout << EdgeMatrix[i][j]<< ", ";
		}
		cout << endl;
	}
}

// PrintAdiacents
void PrintAdiacents();

// Adiacent()
// Check if two nodes are adiacents
vector<int> Adiacent(unsigned int NodeNum1, unsigned int NodeNum2);

// IsConnected()
// Return True if the graph is connected, False else
bool IsConnected();
