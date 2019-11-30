#include <iostream>

using namespace std;

int n, contador;
int formas[10+1];

bool columna[10+1];

int torres[10+1];

void coloca(int k)
{
	if (k == n) {
		for (int i=0;i<n;++i)
			cout << torres[i] << ' ';
		cout <<'\n';
		contador+=1;
		return;
	}
	else
	{
		for (int i=0;i<n;++i)
		{
			if ( columna[i] ) continue;
			torres[k] = i+1;
			columna[i] = true;

			if ( torres[k]%formas[k] != 0 )
			{
				coloca(k+1);
			}

			columna[i] = false;
			torres[k] = 0;
		}
	}
}

int main()
{
	cin >> n;
	for (int i=0;i<n;++i) {
		cin >> formas[i];
	}

	coloca(0);

	cout << contador << '\n';

	return 0;
}