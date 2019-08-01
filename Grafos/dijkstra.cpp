#include <iostream>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main()
{
	int v, e;

	cin >> v >> e;

	vector< pair<int,int> > AdjList[v+1];

	int x, y, w;

	for (int i=0;i<e;++i)
	{
		cin >> x >> y >> w;
		AdjList[x].push_back({ y, w });
		AdjList[y].push_back({ x, w });
	}

	int distance[v+1];
	bool processed[v+1];

	memset( processed, false, sizeof processed );

	for (int i = 1; i <= v; i++) distance[i] = INF;

	cin >> x;

	priority_queue< pair<int,int> > q;
	distance[x] = 0;

	q.push({0,x});

	while (!q.empty()) {		

		int a = q.top().second; 

		int negdis = q.top().first;	
		cout << "neg: "<< negdis << ' ';

		q.pop();

		if (processed[a]) {
			cout << "skipping " << a << '\n';
			continue;	
		} 

		processed[a] = true;

		for (auto u : AdjList[a]) {
			int b = u.first, w = u.second;

			cout << a <<" "<< b << " " << w << '\n';
			cout << "comparing: \n";
			cout << distance[a]+w <<" < "<< distance[b] << '\n';

			if (distance[a]+w < distance[b]) {
				distance[b] = distance[a]+w;
				cout << "pushing: " << -distance[b] <<" " <<b << '\n';
				q.push({-distance[b],b});
			}
		}
	}

	for (int i=1; i <= v; ++i)
	{
		cout << x << " -> " << i << ":\t" << distance[i] << '\n';
	}

	return 0;
}