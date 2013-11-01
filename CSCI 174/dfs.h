#ifndef DFS_H
#define DFS_H

#include "graph.h"
#include "adjacency.h"
#include <vector>
#include <stack>

#define WHITE 0
#define GRAY 1
#define BLACK 2

class DFS
{
public:
	DFS(ADJACENCY);
	~DFS();

	int time;
	void search(ADJACENCY g);
	int graphSize;

	std::stack <int> getPostOrder();
	void visit(ADJACENCY g, int v);

private:
	std::vector <int> color;
	std::vector <int> parent;
	std::vector <int> discovered;
	std::vector <int> finished;
	std::stack <int> postOrder;

};

DFS::DFS(ADJACENCY g)
{
	graphSize = g.getList().size();

	color.resize(graphSize);
	parent.resize(graphSize);
	discovered.resize(graphSize);
	finished.resize(graphSize);

	search(g);
}

DFS::~DFS()
{
}

void DFS::search(ADJACENCY g)
{
	time = 0;

	for (int x = 0; x < graphSize; x++)
	{
		color[x] = WHITE;
		parent[x] = -1;
	}

	for (int x = 0; x < graphSize; x++)
	{
		if (color[x] == WHITE)
			visit(g, x);
	}

}

void DFS::visit(ADJACENCY g, int i)
{
	time++;
	discovered[i] = time;

	color[i] = GRAY;

	std::vector <LIST *> list = g.getList();

	LIST *adj = list[i]->next;

	for (LIST *node = adj; node != NULL; node = node->next)
	{
		if (color[node->getDATA().getValue()] == 0)
		{
			parent[node->getDATA().getValue()] = i;

			int x = node->getDATA().getValue();
			visit(g, x);
		}
	}

	color[i] = BLACK;

	time++;
	finished[i] = time;

	postOrder.push(i);

}

std::stack <int> DFS::getPostOrder()
{
	return postOrder;
}

#endif