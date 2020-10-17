#include <iostream>
#include <vector>
#include <queue>
#define INT_MAX       2147483647    // maximum (signed) int value
#define ULONG_MAX     0xffffffffUL  // maximum unsigned long value
using std::vector;
using std::queue;

using std::pair;
using std::priority_queue;
using std::swap;
using std::pair;
using std::make_pair;


vector < long > dist;
vector < int > prev;
queue <int> nodes;
vector <int> result;

int size;
vector<int> data_;
vector< pair<int, int> > swaps_;

int LeftChild(int x)
{
	return (2 * x);
}
int RightChild(int x)
{
	return ((2 * x) + 1);
}
void ShiftDown(int x)	// here 0
{
	//x = x - 1;
	int maxIndex = x;
	int l = LeftChild(x);
	if ((l - 1 <= size))			// here 0
		if (data_[l - 1] < data_[maxIndex - 1])
			maxIndex = l;
	int r = RightChild(x);
	if ((r - 1 <= size))			// here 0
		if (data_[r - 1] < data_[maxIndex - 1])
			maxIndex = r;
	if (x != maxIndex)
	{
		swap(data_[x - 1], data_[maxIndex - 1]);
		swaps_.push_back(make_pair(x - 1, maxIndex - 1));
		ShiftDown(maxIndex);
	}

}
void BuildHeap()	// here 1
{
	size = data_.size() - 1;
	for (int i = (data_.size() / 2); i >= 1; i--)
	{
		ShiftDown(i);
	}
}

void dijktra(vector<vector<int> > &adj, vector<vector<long> > &cost, int s)
{
	dist[s] = 0;
	priority_queue <int, vector<int>, std::greater<int>> sptSet;
	sptSet.push(s);
	//data_.push_back(s);

	//while (data_.size() != NULL)
	while (sptSet.size() != NULL)
	{
		int u = sptSet.top();
		sptSet.pop();

		/*int u = data_[0];
		data_.erase(data_.begin());
*/
		vector<int> &temp = (adj[u]);
		for (int i = 0; i < temp.size(); ++i)
		{
			if (dist[temp[i]] > (dist[u] + cost[u][i]))
			{
				dist[temp[i]] = (dist[u] + cost[u][i]);
				prev[temp[i]] = u;
				sptSet.push(temp[i]);

				/*data_.push_back(temp[i]);
				BuildHeap();*/
			}
		}


	}


}

long distance(vector<vector<int> > &adj, vector<vector<long> > &cost, int s, int t)
{
	//write your code her
	dijktra(adj, cost, s);

	if (dist[t] == INT_MAX)
		return -1;
	else
		return dist[t];
}


int main() {
	int n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<vector<long> > cost(n, vector<long>());
	dist.assign(n, INT_MAX);
	prev.assign(n, NULL);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1].push_back(y - 1);
		cost[x - 1].push_back(w);
	}
	int s, t;
	std::cin >> s >> t;
	s--, t--;
	std::cout << distance(adj, cost, s, t);
}

