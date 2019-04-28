#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
#include <algorithm>
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

	while(getline(cin,buffer))
	{
		reverse(buffer.begin(),buffer.end());
		for (auto& i: buffer)
		{
			cout << i;
		}
		cout << '\n';
	}

	return 0;
}