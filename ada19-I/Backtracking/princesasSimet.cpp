#include <cstdio>

int n, res;
int answersPerColumn[12+1];

bool columna[12+1];
bool noDisponible[12+1][12+1];

int princesas(int fila)
{
	if ( fila == n ) {
		return 1;
	}
	for (int i=0; i < n; ++i) {
		if ( columna[i] || noDisponible[fila][i] )  {
			continue;
		}

		columna[i] = true;		
		noDisponible[fila+1][i-1] = true;
		noDisponible[fila+1][i+1] = true;

		answersPerColumn[i] += princesas(fila+1);	

		noDisponible[fila+1][i-1] = false;
		noDisponible[fila+1][i+1] = false;
		columna[i] = false;
	}
	return 0;
}

int main()
{		
	scanf("%d",&n);

	if (n <= 1)
		printf("1\n");
	else {
		if (  n%2==0 ) {
			for (int i=n-1;i>=n/2;--i) 
				noDisponible[0][i] = true;
			princesas(0);
			for (int i=0; i<n; ++i) res += answersPerColumn[i];
			printf("%d\n", res<<1);
		} 
		else 
		{
			for (int i=n-1;i>n/2;--i)
				noDisponible[0][i] = true;			
			princesas(0);
			for (int i=0; i<n ; ++i) if (i!=n/2) res += answersPerColumn[i];
			printf("%d\n", res<<1);
		}
	}
	
	for (int i=0;i<n;++i) {
		printf("%d ",answersPerColumn[i]);
	} printf("\n");
	
	return 0;
}