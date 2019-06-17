#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, a, d, k;
	
	cin >> c;
	
	string s;
	getline(cin,s);

	int coeficientes[20+1];

	for (int i=0; i<c ;++i)
	{
		getline(cin,s);

		stringstream ss(s);

		int index = 0;

		while(ss >> a)
		{
			coeficientes[index++] = a;
		}
		cin >> d >> k;

		int offset=0;

		for (int i=0;i<index;++i)
		{
			if ( k <= coeficientes[i] * d )
			{
				printf("%d\n",coeficientes[i]*d + offset);
			}
			else 
			{
				offset+=coeficientes[i]*d;
			}
		}
	}

	return 0;
}