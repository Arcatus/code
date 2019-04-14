#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
#include <string>
#include <cctype>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string cad;

	getline(cin,cad);

	int contador = 0, res = 0;

	for (int i = 0; i < cad.length(); ++i)
	{
		if ( isdigit(cad[i]) )
		{
			contador++;
			res += cad[i] - '0';
		}
	}
	cout << contador << " " << res << '\n';
	return 0;
}