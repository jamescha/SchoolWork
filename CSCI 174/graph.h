#include "data.h"
#include <vector>

#ifndef GRAPH_H
#define GRAPH_H

class GRAPH
{
public:
	GRAPH();

	void createUndirectedGraph(int);
	void createDirectedGraph(int);
	void print();

	std::vector <std::vector <DATA>> getGraph();

private:
	bool checkDup(int, std::vector <DATA>);
	std::vector <std::vector <DATA>> graph;
};

GRAPH::GRAPH(){}

void GRAPH::createUndirectedGraph(int size)
{
	int input = 0;
	DATA tempData;
	graph.resize(size);

	for (int i=0; i<size; i++)
	 {
		 input = 0;

		 while ( input != -1 && graph.size()-1 != graph[i].size())
		 {
			 cout <<"\n\nWhat is connected to node " << i << " (-1 to end range 0 to " << size-1 << " )?	";
			 cin >> input;
			 
			 if (input != -1)
			 {
				 if(input >= 0 && input < size && input != i)
				 {
					if(!checkDup(input,graph[i]))
					{
						tempData.setValue(input);
						graph[i].push_back(tempData);
						tempData.setValue(i);
						graph[input].push_back(tempData);
					}
					else
						cout << "That value is a duplicate";
					
				 }
				 else
					 cout << "That input is out of range" << endl;
			 }
		 }
	 }
}

void GRAPH::createDirectedGraph(int size)
{
	int input = 0;
	DATA tempData;
	graph.resize(size);

	for (int i=0; i<size; i++)
	 {
		 input = 0;

		 while ( input != -1 && graph.size() != graph[i].size())
		 {
			 cout <<"\n\nWhat is connected to node " << i << " (-1 to end range 0 to " << size-1 << " )?	";
			 cin >> input;
			 
			 if (input != -1)
			 {
				 if(input >= 0 && input < size)
				 {
					if(!checkDup(input,graph[i]))
					{
						tempData.setValue(input);
						graph[i].push_back(tempData);
					}
					else
						cout << "That value is a duplicate";
					
				 }
				 else
					 cout << "That input is out of range" << endl;
			 }
		 }
	 }
}

void GRAPH::print()
{
	for(unsigned int i = 0; i < graph.size(); i++)
	{
		cout << i << "| ";
		for(unsigned int j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j].getValue() << " ";
		}
		cout << endl;
	}
}

bool GRAPH::checkDup(int x, std::vector <DATA> y)
{	
	if(y.size()>0)
		for(unsigned int i = 0; i < y.size(); i++)
			if ( y[i].getValue() == x)
				return true;

	return false;
}

std::vector <std::vector <DATA>> GRAPH::getGraph()
{
	return graph;
}

#endif