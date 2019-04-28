#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
#include <string>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int cuenta[128];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	string buffer;

	cin >> buffer;

	//56 ascii 8

	for (int i = 0; i < n; ++i)
	{
		cuenta[buffer[i]]++;
	}
	// turnos totales
	int diff = n - 11;

	int turnos_petia = diff/2;

	cout << cuenta[56] << '\n';

	if ( cuenta[56] >= turnos_petia  ) // posibilidad de borrar todos los 8 
	{
		cout << "YES" << '\n';
	}
	else
	{
		cout << "NO" << '\n';
	}
	return 0;
}