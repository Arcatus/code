#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
	
	ios::sync_with_stdio(0);
	
	int n;

	cin >> n;

	vector<int> a(n);

	for(int i=0; i<n; ++i) {
		cin >> a[i];
	}

	map<int,int> dp;

	int ans = 0;
	int valor_maximo = 0;

	for(int i=0; i<n; ++i) {
		int x = a[i];
		dp[x] = dp[x - 1] + 1;
		if ( ans < dp[x] ) {
			ans = dp[x];
			valor_maximo = x;
		}
	}
	cout << ans << '\n';

	vector <int> indices;

	for(int i = n-1; i>= 0; i--) {
		if ( a[i] == valor_maximo ) {
			indices.push_back(i+1);
			valor_maximo--;
		}
	}

	for(int i=indices.size()-1; i>=0;i--) {
		cout << indices[i] << ' ';
	}
	cout << '\n';
}