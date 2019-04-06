#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
#include <string>
#include <map>
#include <stack>

using namespace std;

int main()
{
	char opc; string input;

	stack<string> monton;
	map<string,int> registro;

	int layers = 1;

	while(cin >> opc)
	{
		if (opc == 'D')
		{
			cin >> input;
			monton.emplace( input );
			registro.emplace( input, layers++ );
		}
		else if ( opc == 'P')
		{	
			cin >> input;
			cout << monton.size() - registro[input] << '\n';
		}
		else
		{
			monton.pop();
			layers--;
		}
	}
}