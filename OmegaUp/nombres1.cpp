#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	int n;
	cin >> n;

	queue<string> cola;
	getline(cin,s);

	stringstream stream;

	while(getline(cin,s))
	{
		stream.str(s);
		getline(stream,t,' ');
		cout << t << '\n';
		getline(stream,t,'\n');
		cola.push(t);
		stream.clear();
	}
	while(!cola.empty())
	{
		cout << cola.front() << '\n';
		cola.pop();
	}
	return 0;
}