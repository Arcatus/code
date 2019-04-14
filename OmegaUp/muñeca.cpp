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

	int piedras;
	cin >> piedras;

	int contador = 0;

	while(piedras > 0)
	{
		contador += piedras*2;
		piedras--;
	}

	cout << contador << '\n';
}