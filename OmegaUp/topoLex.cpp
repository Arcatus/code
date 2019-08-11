#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;

	cin >> n >> m;
	
	int indegree[n];

	for (int i=0; i<n; ++i) {
		indegree[i] = 0;
	}

	int x, y;

	vector<int> outGoingList[n];

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		outGoingList[x].push_back(y);
		indegree[y]+=1;
 	}

 	priority_queue<int, vector<int>, greater<int> > L;

 	for (int i=0; i<n; ++i) {
 		if (indegree[i] == 0) {
 			L.push(i);
 		}
 	} 	

 	vector<int> ans;

 	while ( !L.empty() ) {
 		
 		int u = L.top();
 		L.pop();

 		ans.push_back(u);

 		for (int i=0; i < outGoingList[u].size(); ++i) {

 			indegree[ outGoingList[u][i] ] -= 1;

 			if ( indegree[ outGoingList[u][i] ] == 0 ) {
 				L.push( outGoingList[u][i] );
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