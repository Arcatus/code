//#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

int n; 

vi adj[10];

vector<bool> visited;

vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
	int n;
	scanf("%d",&n);

	/* code */
}