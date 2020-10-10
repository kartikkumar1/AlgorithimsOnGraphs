#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::pair;

vector < bool > explored;

void Explore(vector<vector<int> > &adj, int v)
{
	explored[v] = true;
	vector<int> &temp = (adj[v]);
	for (int i = 0; i < temp.size(); ++i)
	{
		if (explored[temp[i]] != true)
			Explore(adj,temp[i]);
	}
}

int reach(vector<vector<int> > &adj, int x, int y)
{
	//write your code here

	vector<int> &temp = (adj[x]);

	Explore(adj, x);
	if (explored[y] == true)
		return 1;
	else
		return 0;
	
}

int main()
{
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	explored.assign(n, false);
	for (size_t i = 0; i < m; i++)
	{
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	std::cin >> x >> y;
	std::cout << reach(adj, x - 1, y - 1);
}
