#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int a, b, n;
const long long INF = LLONG_MAX;

int max_pasos = 100000;

long long pasos(int k, int p)
{
	if (max_pasos == 0)
		return INF;
	else if ( n == k ) return p;
	else 
	{
		long long x = INF, y = INF;

		if ( k < n ) {
			max_pasos--;
			x = pasos( (k*a>9999)?1:k*a, p+1);
			max_pasos++;
		}
		else 
		{
			max_pasos--; 	
			y = pasos( k/b, p+1);
			max_pasos++;
		}
		return min(x,y);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	

	cin >> a >> b >> n;
	cout << pasos(1,0) << '\n';

	return 0;
}