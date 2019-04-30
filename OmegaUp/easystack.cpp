#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>
#include <stack>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int opc;
	int t;
	stack<int> mipila;
	for(int i=0;i<n;++i)
	{
		cin >> opc;

		if (opc==1) {
			cin >> t;
			mipila.push(t);
		} else if (opc==2) {
			
			if (!mipila.empty()) mipila.pop();

		}else{
			if (!mipila.empty())
			{
				cout << mipila.top() << '\n';
			}
			else
			{
				cout << "Empty!\n";
			}
		}
	}

	return 0;
}