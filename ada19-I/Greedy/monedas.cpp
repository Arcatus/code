#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	bool arr[n];

	for (int i=0;i<n;++i) {	
		cin >> arr[i];
	}

	int contador=0;

	for (int i=0;i<n-m+1;++i) {
		if ( !arr[i] ) {
			contador+=1;
			for ( int j = i; j < i+m; ++j) {
				arr[j] ^= 1;
			}
		}
	}

	int ans = count(arr,arr+n,1);	

	cout << ((ans == n)?contador:-1) << '\n';

	return 0;
}