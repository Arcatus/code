#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>
#include <climits>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int max = INT_MIN;	
	int indice;
	int t;
	for (int i = 0; i< 10; ++i)
	{
		cin >> t;
		if (t>max)
		{
			max=t;
			indice=i;
		}	
	}

	cout << max << " " << indice<<'\n';
	
	return 0;
}