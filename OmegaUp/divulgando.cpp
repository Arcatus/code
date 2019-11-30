#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, amigo;

	cin >> n;

	queue<int> q;
	vector<int> AdjList[n];

	vector<int> visited(n, -1);

	for (int i=0; i<n; ++i) {
		cin >> a;
		for (int j=0; j<a; ++j) {
			cin >> amigo;
			AdjList[i].push_back(amigo);
		}
	}
	
	int inicial;
	cin >> inicial;

	visited[inicial] = 0;

	q.push(inicial);

	int dias[1010] = { };

	while (!q.empty()) {

		int u = q.front();
		q.pop();		
		for (int j = 0; j < (int)AdjList[u].size(); j++) {
			int v = AdjList[u][j];

			if (visited[v] == -1) {
				visited[v] = visited[u] + 1;
				dias[visited[v]]+=1;
				q.push(v);
			}
		}
	}
	int ans = 0;
	for (int i=1; i<=n; ++i) {
		ans = max( ans, dias[i] );
	}
	cout << ans << '\n';
}