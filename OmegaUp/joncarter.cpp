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

char arr[1000 + 1];

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int p, s, b;

	cin >> p >> s >> b;

	string carretera;

	cin >> carretera;

	int timepo = 0;

	for (int i = 0; i < carretera.length(); ++i)
	{
		if (carretera[i] == '-')
		{
			timepo += p;
		}
		else if (carretera[i] == '/')
		{
			timepo += s;
		}
		else
		{
			timepo += b;
		}
	}
	cout << timepo << '\n';
}