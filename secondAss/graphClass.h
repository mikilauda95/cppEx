#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H

#include <vector.h>
use namespace std;

class GraphClass
{
private:
	unsigned int NumNodes;	
	vector<NumNodes, vector<unsigned int> > EdgeMatrix(NumNodes);
	vector<NumNodes> ValueVector;

public:
	// Void Constructor
	GraphClass(float prob = 0.0);
	// Copy Constructor
	GraphClass(const GraphClass& G);
	// Destructor
	virtual ~GraphClass();

	// AddNode()
	// To be done later. For the moment fixed dimension.
	//AddNode();

	// RemoveNode()
	// For the moment eliminating a node will simply correspond to zero its column and row
	//RemoveNode(NodeNum);
	
	// GetNodeValue
	// Return the node value/name assigned (if it exist)
	GetNodeValue(unsigned int NodeNum, unsigned int NodeNum);

	// SetNodeValue
	// Set the node value/name to a certain node 
	SetNodeValue(string NodeName, unsigned int NodeNum);
	
	// GetAdiacents()
	// Return a vector of all the adiacents node (edge > 0)
	vector<int> GetAdiacents();

	// GetNumEdges
	// Return the number of edges > 0
	GetNumEdges(unsigned int NodeNum);

	// RemoveEdge
	// Remove an Edge between two nodes
	RemoveEdge(unsigned int NodeNum1, unsigned int NodeNum2);

	// GetEdgeValue
	GetEdgeValue(unsigned int NodeNum);

	// SetEdge
	SetEdge(unsigned int NodeNum1, unsigned int NodeNum2);

	// PrintGraph
	// Print the graph as an adjiacency list
	PrintGraph();
	
	// PrintAdiacents
	PrintAdiacents();

	// Adiacent()
	// Check if two nodes are adiacents
	Adiacent(unsigned int NodeNum1, unsigned int NodeNum2);

	// IsConnected()
	// Return True if the graph is connected, False else
	IsConnected();
};

#endif /* GRAPHCLASS_H */
