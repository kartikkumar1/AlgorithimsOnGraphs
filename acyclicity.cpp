#include <iostream>
#include <vector>

using std::vector;
using std::pair;
int pass = 0;

vector < bool > explored;
vector < int > pre;
vector < int > post;
int cycle = 1;

void previsit(int v) {
	pre[v] = cycle;
	cycle++;
}
void postvisit(int v) {
	post[v] = cycle;
	cycle++;
}

vector <bool> recursion;

void Explore(vector<vector<int> > &adj, int v)
{
	explored[v] = true;
	vector<int> &temp = (adj[v]);
	//if (pre[v] == 0)
	//	previsit(v);
	//else
	//{
	//	//pass = 1;
	//	return;
	//}
	if (recursion[v] == true)
	{
		pass = 1;
		std::cout << "1";
		//return 0;
		exit(0);
		//return;
	}


	recursion[v] = true;
	for (int i = 0; i < temp.size(); ++i)
	{

		Explore(adj, temp[i]);

		//postvisit(v);
		/*if (explored[temp[i]] == true)
			pass = 1;
		else
			Explore(adj, temp[i]);*/

	}
	recursion[v] = false;
	/*if (post[v] == 0)
		postvisit(v);
	*///return 0;
}

int acyclic(vector<vector<int> > &adj)
{
	//write your code here
	//vector<int> &temp = (adj[x]);
	for (int i = 0; i < adj.size(); ++i)
	{
		Explore(adj, i);
	}

	//int test = post[0];
	//int max = ((adj.size()) * 2);
	//if ( test != max)
	////if( post[0] == (2* pre[0]))
	//	pass = 1;

	 return pass;
	//return 0;
}

int main()
{
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	explored.assign(n, false);
	recursion.assign(n, false);
	pre.assign(n, 0);
	post.assign(n, 0);
	for (size_t i = 0; i < m; i++)
	{
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	std::cout << acyclic(adj);
}
