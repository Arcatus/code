#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indegree[100000+1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;

	cin >> n >> m;

	int x, y;

	vector< vector<int> > adjList(n);

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		adjList[x].push_back(y);
		indegree[y]++;
 	}

 	priority_queue<int, vector<int>, greater<int> > L;

 	for (int i=0; i<n; ++i) {
 		if ( !indegree[i] ) {
 			L.push(i);
 		}
 	} 	

 	vector<int> ans;

 	while ( !L.empty() ) {
 		
 		int u = L.top();
 		L.pop();

 		ans.push_back(u);

 		for (int i=0; i < adjList[u].size(); ++i) {

 			indegree[ adjList[u][i] ] -= 1;

 			if ( !indegree[ adjList[u][i] ] ) {
 				L.push( adjList[u][i] );
 			}
 		}
 	}

 	if ( ans.size() != n ) {
 		cout << -1 << '\n';
 	} else {
 		for (auto i: ans) {
 			cout << i << ' ';
 		}
 		cout << '\n';
 	}
}