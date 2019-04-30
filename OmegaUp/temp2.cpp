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

	int c;
	cin >> c;

	int faren= c*1.8f + 32;
	int kelvin = c + 273.15f;
	int remur = c *0.8f;
	
	printf("%d %d %d\n",kelvin,faren,remur);

	return 0;
}