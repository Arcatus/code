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

struct point
{
	int x; 
	int y;
	int dist[8];
};
	
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	cin >> n;

	point arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].x >> arr[i].y;
	}

	int i, j;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			arr[i].distance[j] arr[i].x
		}
	}

}