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
int cuentas[126];
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	cin >> n;
	string buffer;
	
	cin >> buffer;

	for (int i = 0; i < n; ++i)
	{
		cuentas[buffer[i]]++;
	}
	int max = -1;
	int pos;
	for (int i = 0; i < 126; ++i)
	{
		if ( cuentas[i] > max)
		{
			max = cuentas[i];
			pos = i;
		}
	}

	printf("%c\n",pos);

	return 0;
}