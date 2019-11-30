#include <iostream>

using namespace std;

int contador, m, b;

char array[32+1];

void genera(int k)
{	
	if (k == m)
	{
		if (b == 0) contador+=1;
		return;
	}
	if ( b > 0 && array[k-1] != '1') {
		b-=1;
		array[k] = '1';
		genera(k+1);
		array[k] = '0';
		b+=1;
	}
	genera(k+1);
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);

	cin >> m >> b;	

	for (int i=0;i<m;++i) array[i] = '0';

	genera(0);

	cout << contador << '\n';

	return 0;
}