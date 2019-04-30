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
	cin >> n >> m;

	float t = (m*1500.0f) / (n*300.0f);

	printf("%.1f horas.\n",t);

	return 0;
}