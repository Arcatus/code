#include <iostream>

using namespace std;

int n;
int binomial[10][10];

unsigned long long colorea(int columna, int k)
{	
	if (columna == n) {
		return 1;
	}
	else
	{
		unsigned long long res = 0LL;
		for(int i=0; i <= n-k;++i)
		{			
			res += binomial[n][i] * colorea(columna+1,i);
		}
		return res;
	}
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	binomial[2][0] = binomial[2][2] = 1;
	binomial[2][1] = 2;

	binomial[3][0] = binomial[3][3] = 1;
	binomial[3][1] = binomial[3][2] = 3;

	binomial[4][0] = binomial[4][4] = 1;
	binomial[4][1] = binomial[4][3] = 4;
	binomial[4][2] = 6;

	binomial[5][0] = binomial[5][5] = 1;
	binomial[5][1] = binomial[5][4] = 5;
	binomial[5][2] = binomial[5][3] = 10;

	binomial[6][0] = binomial[6][6] = 1;
	binomial[6][1] = binomial[6][5] = 6;
	binomial[6][2] = binomial[6][4] = 15;
	binomial[6][3] = 20;

	binomial[7][0] = binomial[7][7] = 1;
	binomial[7][1] = binomial[7][6] = 7;
	binomial[7][2] = binomial[7][5] = 21;
	binomial[7][3] = binomial[7][4] = 35;

	binomial[8][0] = binomial[8][8] = 1;
	binomial[8][1] = binomial[8][7] = 8;
	binomial[8][2] = binomial[8][6] = 28;
	binomial[8][3] = binomial[8][5] = 56;
	binomial[8][4] = 70;

	binomial[9][0] = binomial[9][9] = 1;
	binomial[9][1] = binomial[9][8] = 9;
	binomial[9][2] = binomial[9][7] = 36;
	binomial[9][3] = binomial[9][6] = 84;
	binomial[9][4] = binomial[9][5] = 126;

	cout << colorea(0,0) << '\n';

	return 0;
}