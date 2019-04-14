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

	int n, t, contador=0;
	cin >> n;

	stack<int> autos;

	for (int i = 0; i<n; ++i)
	{
		cin >> t;
		autos.push(t);
	}
	int solicitado;
	cin >> solicitado;

	bool found = false;
	while( !autos.empty() )
	{	
		t = autos.top();
		autos.pop();
		contador++;
		if ( t == solicitado )
		{
			found = true; break;
		}
	}

	if ( found ) 
	{
		cout << contador << '\n';
	}
	else
	{
		cout << "No existe el auto" << '\n';
	}

	return 0;
}