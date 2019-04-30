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

	float n;
	
	cin >> n;

	if ( n <= 59.99f )
	{
		cout << "F\n";
	}
	else if (n <= 66.99f)
	{
		cout << "D\n";
	}
	else if (n <= 69.99f)
	{
		cout << "D+\n";
	}
	else if (n <= 72.99f)
	{
		cout << "C-\n";
	}
	else if (n<=76.99f)
	{
		cout << "C\n";
	}
	else if (n<=79.99f)
	{
		cout << "C+\n";
	}
	else if (n<=82.99f)
	{
		cout << "B-\n";
	}
	else if (n<=86.99f)
	{
		cout << "B\n";
	}
	else if (n<=89.99f)
	{
		cout << "B+\n";
	}
	else if (n<=92.99f)
	{
		cout << "A-\n";
	}
	else
	{
		cout << "A\n";
	}

	return 0;
}