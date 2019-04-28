#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
#include <string>
#include <stack>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string buffer;
	stack<string> t;
	int n;

	cin >> n;

	for(int i = 0;i<n;++i){
		cin >> buffer;
		t.push(buffer);
	}	

	while(!t.empty())
	{
		cout << t.top()<<'\n';
		t.pop();
	}

	return 0;
}