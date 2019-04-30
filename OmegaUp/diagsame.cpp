#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n, m;

	cin >> n;

	int a[n * n];


	for (int i=0;i<n;++i) {
		for (int j=0;j<n;++j) {
			cin >> a[i*n + j];
		}
	}

	for (int i=0,j=0,k=n-1; i<n; i++,j++,k--) {
		if ( a[i*n + j] != a[i*n + k] )
		{	
			cout << "No Iguales" << '\n';
			return 0;
		}
	}	
	cout << "Iguales" << '\n';

	return 0;
}