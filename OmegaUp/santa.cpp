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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string nino;
	int acciones;

	int a;
	char opc;
	for (int i=0;i<n;++i)
	{
		a=0;	
		cin >> nino;
		cin >> acciones;
		for (int j=0;j<acciones;++j) {
			cin >> opc;
			a += ((opc=='B')?1:(-2));
		}
		cout << nino << ' ';
		cout << ((a > 0)?"REGALO":"CARBON") << '\n';
	}

	return 0;
}