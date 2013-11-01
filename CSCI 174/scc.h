#ifndef SCC_H
#define SCC_H

#include <vector>
#include <stack>
#include "adjacency.h"
#include "dfs.h"

class SCC
{
public:
	SCC(ADJACENCY);
	~SCC();

	int count;
	std::vector <int> visited;
	std::vector <int> scc;

	int countSCC(int x);
	int getCount();

private:
	void dfs(std::vector <LIST *> a, int x);


};

SCC::SCC(ADJACENCY a)
{
	visited.resize(a.getList().size());
	scc.resize(a.getList().size());

	count = 0;

	DFS dfsT = *new DFS(a);
	std::stack <int> postOrder = dfsT.getPostOrder();

	std::vector <LIST *> reverseA = a.getReverseList();

	while (!postOrder.empty())
	{
		if (visited[postOrder.top()] == 0)
		{
			dfs(reverseA, postOrder.top());

			count++;
		}

		postOrder.pop();
	}
}

void SCC::dfs(std::vector <LIST *> a, int x)
{
	visited[x] = GRAY;
	scc[x] = count;

	std::vector <LIST *> list = a;

	LIST *adj = list[x]->next;

	for (LIST *node = adj; node != NULL; node = node->next)
	{
		if (visited[node->getDATA().getValue()] == 0)
		{
			dfs(a, node->getDATA().getValue());
		}
	}
}

int SCC::countSCC(int x)
{
	return scc[x];
}

int SCC::getCount()
{
	return count;
}

SCC::~SCC()
{
}

#endif