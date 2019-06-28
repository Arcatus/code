#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, x, y;

	cin >> n;

	vector<int> AdjList[n];

	for (int i=0;i<n-1;++i)
	{
		cin >> x >> y;
		AdjList[x].push_back(y);
	}

	queue<int> q;

	q.push(0);

	while (!q.empty()) {

		int u = q.front();
		q.pop();

		cout << u << ' ';

		if ( AdjList[u].size() == 1 )
		{
			q.push(AdjList[u][0]);
		}
	}
}