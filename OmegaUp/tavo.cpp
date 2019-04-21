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
	ios::sync_with_stdio(false);
	cin.tie(0);

	char a;
	int contador=0;
	while(cin>>a)
	{
		if (a =='*')
			contador++;
	}

	if (contador <= 2)
		cout << "BIEN" << '\n';
	else if ( contador == 2 )
		cout << "HAPPY" << '\n';
	else
		cout << "BUSCAR A TAVO" << '\n';

	return 0;
}