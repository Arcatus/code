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

	char a;
	cin >> a; int contador=0;
	while(a != '.')
	{
		if (a=='A') contador++;
		cin >> a;
	}

	cout << contador << '\n';
	return 0;
}