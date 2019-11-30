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

	char c;

	bool modo = true;

	while( scanf("%c",&c)==1 )
	{
		if (c == 34)
		{
			c = (modo)?96:39;
			putchar(c);
			putchar(c);
			modo = !modo;
			continue;
		}
		putchar(c);
	}
}