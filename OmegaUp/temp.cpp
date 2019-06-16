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
	
	float n;
	cin >> n;
	
	if (n >= 8.0f)
	{
		printf("NO CAFE\n");
	}
	else 
	{
		//printf("%.2f\n",(8.0f - n)*1.5f);
		cout << (8.0f - n)*1.5f << '\n';
	}

	return 0;
}