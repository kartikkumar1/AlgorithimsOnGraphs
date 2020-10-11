#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

vector < int > dist;
vector < int > prev;
queue <int> nodes;
vector <int> result;

void RconstructPath(int S, int u)
{

	while (u != S)
	{
		if (u == -1)
		{
			std::cout << "-1";
			exit(0);
		}
		result.push_back(u);
		u = prev[u];
	}

}

void bfs(vector<vector<int> > &adj, int s)
{
	dist[s] = 0;
	prev[s] = 0;
	nodes.push(s);
	while (nodes.size() != NULL)
	{
		int u = nodes.front();
		nodes.pop();
		vector<int> &temp = (adj[u]);

		for (int i = 0; i < temp.size(); ++i)
		{
			if (dist[temp[i]] == -1)
			{
				nodes.push(temp[i]);
				dist[temp[i]] = dist[u] + 1;
				prev[temp[i]] = u;
			}
		}
	}
}

int distance(vector<vector<int> > &adj, int s, int t)
{
	//write your code here
	bfs(adj, s);
	//if (s == -1 | t == -1)
	//	return -1;
	if (s == t )
		return 0;
	//RconstructPath(0,s);
	RconstructPath(s, t);
	int size = result.size();
	if (size != NULL)
		return size;
	else
	{
		return -1;
	}

}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	prev.assign(n, -1);
	dist.assign(n, -1);
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int s, t;
	std::cin >> s >> t;
	s--, t--;
	std::cout << distance(adj, s, t);
}
