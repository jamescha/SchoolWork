#include <vector>
#include "graph.h"
#include "data.h"

#ifndef ADJACENCY_H
#define ADJACENCY_H

class LIST{
	
public:
	LIST();
	LIST(LIST *, DATA);
	LIST *next;
	DATA getValue();

private:
	DATA value;


};

LIST::LIST()
{
	next=NULL;
	value.setValue(0);
}

LIST::LIST(LIST *p, DATA x)
{
	next = p;
	value = x;
}

DATA LIST::getValue(){
	return value;
}

class ADJACENCY
{
public:
	ADJACENCY();
	~ADJACENCY();

	void createAdjacencyMatrix (GRAPH);
	void createAdjacencyList (GRAPH);

	void printMatrix();
	void printList();

	std::vector <std::vector <int>> getMatrix();
	std::vector <LIST *> getList();

	std::vector <LIST *> getReverseList();

private:
	std::vector <std::vector <int>> adjacencyMatrix;
	std::vector <LIST *> adjacencyList;
};

ADJACENCY::ADJACENCY()
{
}

ADJACENCY::~ADJACENCY()
{
}

std::vector <LIST *> ADJACENCY::getReverseList()
{ 
	std::vector <LIST *> temp;

	for (int x = getList().size()-1; x > 0; x--)
	{
		temp.push_back(getList()[x]);
	}

	return temp;
}

std::vector <std::vector <int>> ADJACENCY::getMatrix()
{
	return adjacencyMatrix;
}

std::vector <LIST *> ADJACENCY::getList()
{
	return adjacencyList;
}

void ADJACENCY::createAdjacencyMatrix (GRAPH theGraph){
	std::vector <std::vector <DATA>> tempGraph = theGraph.getGraph();
	std::vector <int> tempIntVector(tempGraph.size(), 0);
	std::vector <std::vector <int>> temp(tempGraph.size(), tempIntVector);
	

	for(int i = 0; i < tempGraph.size(); i++)
	{
		for(int j = 0; j < tempGraph[i].size(); j++)
		{
			temp[i][tempGraph[i][j].getValue()]=1;
		}
	}

	 adjacencyMatrix=temp;
}

void ADJACENCY::createAdjacencyList  (GRAPH theGraph){
	std::vector <std::vector <DATA>> tempGraph = theGraph.getGraph();
	std::vector <LIST *> tempListVector(tempGraph.size());
	DATA temp;

	LIST *current = NULL;
	LIST *head = NULL;

	for(int i = 0; i < tempGraph.size(); i++)
	{
		temp.setValue(i);
		current = new LIST(NULL,temp);
		head = current;
		for (int j = 0; j < tempGraph[i].size(); j++)
		{
			current -> next = new LIST(NULL,tempGraph[i][j]);
			current = current ->next;
		}

		adjacencyList.push_back(head);	
	}
}

void ADJACENCY::printMatrix()
{
	cout << " ";
	for (int k = 0; k < adjacencyMatrix.size(); k++)
	{
		cout << " " << k; 
	}
	cout << endl;

	for(int i = 0; i < adjacencyMatrix.size(); i++)
	{
		cout << i << " ";
		for (int j = 0; j < adjacencyMatrix.size(); j++)
		{
			cout << adjacencyMatrix[i][j] << " ";
		}

		cout << endl;
	}

}

void ADJACENCY::printList()
{
	LIST *current;
	for (int i = 0; i < adjacencyList.size(); i++)
	{
		current = adjacencyList[i];
		while (current != NULL)
		{
			cout << current -> getValue().getValue() << " ";
			current = current -> next;
		}

		cout << endl;
	}
	
}

#endif
