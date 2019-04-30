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
	float kelvin = c + 273.15f;
	float rankin = c *((float)9/5) + 491.67f;
	
	printf("%d\n%.2f\n%.2f\n",faren,kelvin,rankin);

	return 0;
}