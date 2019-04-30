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

char abecedario[128];

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	cin >> n;

	char puerco[100];

	int contador=0;
	for (int i=0;i<n;++i)
	{
		scanf("%s",puerco);

		if ( abecedario[ puerco[0] ] == 0 )
		{
			contador++;
			abecedario[ puerco[0] ] = '1';
		}
	}
	printf("%d\n",contador);
	return 0;
}