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

	const int arr[]={ 15,20,19,10,10,5 };

	int res = 0; int a;
	for (int i = 0;i<6;++i)
	{
		cin >> a;
		res += a*arr[i];
	}		

	cout << res << '\n';

	return 0;
}