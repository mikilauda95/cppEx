#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H

#include <iostream>
#include <vector>
using namespace std;

class GraphClass
{
	private:
		unsigned int NumNodes;	
		float Density;	
		vector<vector<unsigned int> > EdgeMatrix;
		vector<string> ValueVector;

	public:
		// Void Constructor
		GraphClass(float D = 0.0, unsigned int N = 50);
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
		void PrintGraph();

		// PrintAdiacents
		void PrintAdiacents();

		// Adiacent()
		// Check if two nodes are adiacents
		vector<int> Adiacent(unsigned int NodeNum1, unsigned int NodeNum2);

		// IsConnected()
		// Return True if the graph is connected, False else
		bool IsConnected();

};

#endif /* GRAPHCLASS_H */
