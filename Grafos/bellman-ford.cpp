#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

const int INF = 1<<20;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int v, e;

	cin >> v >> e;

	int x, y, w;

	vector< tuple<int,int,int> > edges;

	int distance[v+1];

	for (int i=0;i<e;++i)
	{
		cin >> x >> y >> w;

		edges.push_back({ x, y, w });
	}	

	for (int i = 1; i <= v; i++) distance[i] = INF;

	cin >> x;
	distance[x] = 0;

	for (int i = 0; i < v; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a]+w);
		}
	}

	for (int i=1; i <= v; ++i)
	{
		cout << x << " -> " << i << ":\t" << distance[i] << '\n';
	}
	return 0;
}