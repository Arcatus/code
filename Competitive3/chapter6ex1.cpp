#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
#include <cstring>
#include <string>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char buffer[30 + 1];

	string res = "";

	while( scanf("%[^\n]",buffer) == 1)
	{
		for (int i = 0;i<7; ++i)
			if ( buffer[i] == '.' )
				if( i == 6 ) return 0;
			else
				break;
		res += buffer;
	}
	return 0;
}