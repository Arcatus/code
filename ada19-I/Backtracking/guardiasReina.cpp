#include <iostream>
#include <climits>

using namespace std;

struct carta
{
	int sideA;
	int sideB;
};

int turno = 0, ans = -1, m;

carta baraja[18+1];

void guardias(int k)
{	
	for (int i=k; i<m; ++i)
	{
		if ( baraja[k-1].sideB == baraja[i].sideB && ans < m) {
			swap( baraja[i], baraja[k]);
			turno+=1;
			guardias(k+1);
			turno-=1;
			swap( baraja[i], baraja[k]);
		}
		else if ( baraja[k-1].sideA == baraja[i].sideA ans < m) {
			swap( baraja[i] , baraja[k]);
			turno+=1;
			guardias(k+1);
			turno-=1;
			swap( baraja[i], baraja[k]);
		}
	}
	ans = max(ans,turno);
}	

int main()
{
	cin >> m;

	for (int i=0; i<m; ++i)
	{
		cin >> baraja[i].sideA >> baraja[i].sideB;
	}

	for (int i=0; i<m; ++i)
	{
		swap( baraja[i] , baraja[0]);
		turno+=1;
		guardias(1);
		turno-=1;
		swap( baraja[i] , baraja[0]);
	}	
	cout << ans << '\n';

	return 0;
}