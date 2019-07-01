#include <iostream>
#include "Graph.h"
using namespace std;

int main(int argc, char *argv[])
{
	unsigned int NodeNum = 1;
	unsigned int NodeNum1 = 1;
	unsigned int NodeNum2 = 2;
	vector<unsigned int> adiacents;
	bool adiacent;
	unsigned int edgevalue;
	unsigned int numnodes;
	unsigned int numedges;
	unsigned int numnodeedges;
	unsigned int Value = 1;

	float avpathlen;
	Graph G(100, 10);
	G.PrintGraph();
	avpathlen = G.AvPathLen(NodeNum);
	cout << avpathlen << endl;
	G.PrintAvPathLen(NodeNum);

	numnodes = G.GetNumNodes();
	cout << "Number of nodes in the graph is " << numnodes << endl;

	numedges = G.GetNumEdges();
	cout << "Number of edges in the graph is " << numedges << endl;

	adiacents = G.GetAdiacents(NodeNum);
	G.PrintAdiacents(NodeNum);

	numnodeedges =  G.GetNodeNumEdges(NodeNum);
	cout << "Number of edges for node " << NodeNum << " is " << numnodeedges << endl;

	G.RemoveEdge(NodeNum1, NodeNum2);
	G.PrintGraph();

	edgevalue = G.GetEdgeValue(NodeNum1, NodeNum2);
	cout << "edgevalue for nodes " << NodeNum1 << " and " << NodeNum2 << " is " << edgevalue << endl;

	adiacent =  G.Adiacent(NodeNum1, NodeNum2);

	G.SetEdge(NodeNum1, NodeNum2, Value);
	edgevalue = G.GetEdgeValue(NodeNum1, NodeNum2);
	cout << "edgevalue for nodes " << NodeNum1 << " and " << NodeNum2 << " is " << edgevalue << endl;
	

	return 0;
}
