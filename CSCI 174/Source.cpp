using namespace std;

#include <iostream>
#include <vector>
#include "adjacency.h"
#include <time.h>
#include "graph.h"
#include "star.h"
#include "dfs.h"
#include "scc.h"

int main()
{
	GRAPH graph;
	ADJACENCY adjacency;
	int graphType = 0;
	int adjacencyType = 0;
	int graphSize = 0;

	cout << "What kind of graph would you like (0) Undirected (1) Directed? ";
	cin >> graphType;

	cout << "How big would you like your graph? ";
	cin >> graphSize;

	if(!graphType)
		graph.createUndirectedGraph(graphSize);
	else
		graph.createDirectedGraph(graphSize);

	cout << "What kind of adjacency would you like (0) Matrix (1) List?";
	cin >> adjacencyType;

	if(!adjacencyType)
	{
		adjacency.createAdjacencyMatrix(graph);
		adjacency.printMatrix();
	}
	else
	{
		adjacency.createAdjacencyList(graph);
		adjacency.printList();
	}
	
	/*STAR star;
	cout << endl;
	cout << "Star: " << star.findStar(adjacency.getMatrix()) << endl;*/


	SCC sc = *new SCC(adjacency);

	cout << sc.getCount() << endl;


	system("pause");
}
