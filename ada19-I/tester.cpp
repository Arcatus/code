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

int main()
{
	int n;
	cin >> n;	

	int arr[] = 
	{
		1,1,2,4,8,16,32,64,128,256,511
		,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
	};

	cout << arr[n] << '\n';

	return 0;
}