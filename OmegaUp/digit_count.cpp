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
int cuentas[128];
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	cin >> n;

	string buffer;
	getline(cin,buffer);

	for(int i = 0; i <n ; ++i)
	{	
		getline(cin,buffer);

		for (int j=0; j < buffer.length(); ++j)
		{
			cuentas[buffer[j]]++;
		}
	}

	for (int i = 48; i <  58; ++i)
	{
		printf("El %c aparece %d veces.\n",i,cuentas[i]);
	}

	return 0;
}