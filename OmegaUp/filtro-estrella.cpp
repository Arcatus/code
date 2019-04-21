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

	string buffer;

	cin >> buffer;

	for (int i = 0; i < buffer.length(); ++i)
	{
		if (buffer[i] != '0' && buffer[i] != '1')
		{
			cout << "10101" << '\n';
			return 0;
		}	
	}

	cout << buffer << '\n';

	return 0;
}