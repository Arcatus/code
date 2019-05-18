#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>
#include <queue>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<int> heap;

	int t;
	for(int i=0;i<n;++i)
	{
		cin >> t;
		heap.push(t);
	}

	while(!heap.empty())
	{
		cout << heap.top()<< '\n';
		heap.pop();
	}	

	return 0;
}