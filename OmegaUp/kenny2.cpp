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

	int n;
	cin >> n;
	int contador=0;
	for (int i=1; i<=n;++i)
	{
		if(i%3==0) contador++;		
	}

	cout << contador << '\n';

	return 0;
}