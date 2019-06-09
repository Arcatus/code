#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1<<30;

int minimo(const int& a, const int& b, const int& c)
{
	return min(min(a,b),c);
}

int potencia_rara(int p, const int& b, int k)
{
	if ( p == b )
	{		
		return k;
	}	
	else
	{
		int x=INF, y=INF, z=INF;

		if (p < b and p != 0 )
		{
			x = potencia_rara(p+1,b,k+1);
		 	y = potencia_rara(p*2,b,k+1);
		}
		else if (p < b) {
			x = potencia_rara(p+1,b,k+1);
		}
		else {
		 	z = potencia_rara(p-1,b,k+1);
		}
		return minimo(x,y,z);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int b;
	cin >> b;

	if (b == 0)
	{
		cout << "0" << '\n';
	}
	else if(b == 1)
	{
		cout << "1" << '\n';
	}
	else
	{
		cout << potencia_rara(0,b,0) << '\n';
	}

	return 0;
}