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
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	unsigned long long a[n+1];

	a[0]=0;
	a[1]=1;
	if (n==0) {
		cout << "0" <<'\n';
	}
	if ( n>=1 ) {
		cout << "1" <<'\n';
	}	

	for (int i=2;i<=n;++i)
	{
		a[i] = a[i-1] + a[i-2];
		cout << a[i] << '\n';
	}
	
	return 0;
}