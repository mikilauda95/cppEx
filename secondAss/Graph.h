#ifndef Graph_H
#define Graph_H

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
	private:
		unsigned int NumNodes;	
		unsigned int MaxRange;	
		float Density;	
		vector<vector<unsigned int> > EdgeMatrix;
		vector<string> ValueVector;

	public:
		// Void Constructor
		Graph(float D = 0.0, unsigned int N = 50, unsigned int MaxRange = 50);
		// Copy Constructor
		Graph(const Graph& G);
		// Read graph from a file constructor
		Graph(const char* filepath);
		// Destructor
		virtual ~Graph();

		// AddNode()
		// To be done later. For the moment fixed dimension.
		//AddNode();

		// RemoveNode()
		// For the moment eliminating a node will simply correspond to zero its column and row
		//RemoveNode(NodeNum);

		// GetNumNodes()
		// Return the number of nodes 
		unsigned int GetNumNodes();
		
		// GetNumEdges()
		// Return the number of edges of a graph 
		unsigned int GetNumEdges();

		// SetNodeValue
		// Set the node value/name to a certain node 
		void SetNodeValue(string NodeName, unsigned int NodeNum);
		
		// AvPathLen()
		// Compute Average Path Length for a node as the average of the distances to the adiacent nodes (edge > 0)
		float AvPathLen(unsigned int NodeNum);
			
		void PrintAvPathLen(unsigned int NodeNum);

		// GetAdiacents()
		// Return a vector of all the adiacents node (edge > 0)
		vector<unsigned int> GetAdiacents(unsigned int NodeNum);

		// GetNodeNumEdges
		// Return the number of edges > 0
		unsigned int GetNodeNumEdges(unsigned int NodeNum);


		// RemoveEdge
		// Remove an Edge between two nodes (it does not check if it is there because it would simply set to zero an already zero value)
		void RemoveEdge(unsigned int NodeNum1, unsigned int NodeNum2);

		// GetEdgeValue
		unsigned int GetEdgeValue(unsigned int NodeNum1, unsigned int NodeNum2);

		// SetEdge
		void SetEdge(unsigned int NodeNum1, unsigned int NodeNum2, unsigned int Value);

		
		// AddEdge()
		// Like SetEdge but it adds an edge only if there is no edge
		void AddEdge(unsigned int NodeNum1, unsigned int NodeNum2, unsigned int Value);

		// PrintGraph
		// Print the graph as an adjiacency list
		void PrintGraph();

		// PrintAdiacents
		void PrintAdiacents(unsigned int NodeNum);

		// Adiacent()
		// Check if two nodes are adiacents
		bool Adiacent(unsigned int NodeNum1, unsigned int NodeNum2);

		// IsConnected()
		// Return True if the graph is connected, False else
		bool IsConnected();

};

#endif /* Graph_H */
