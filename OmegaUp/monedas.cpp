#include <bits/stdc++.h> 

using namespace std;
using ll = long int;

int a[200000];
int main() 
{ 
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
   	cin >> n;
	for(int i=0; i<n; ++i) cin >> a[i];
	sort(a,a+n);
	ll res = 1;
	for (int i = 0; i < n && a[i] <= res; i++) {
		cerr << a[i] << " <= " << res << '\n';
		res = (ll) res + a[i];		
	}
   	cout << res << endl;
   	return 0; 
}