#include <cstdio>

int main() 
{
	int p[3], N = 3;
	for (int i = 0; i < N; i++) p[i] = i;

	for (int i = 0; i < (1 << N); i++) 
	{
		for (int j = 0; j < N; j++)
		if (i & (1 << j))
		{
			// if bit j is on
			printf("%d ", p[j]);	
		}
		
		// this is part of set
		printf("\n");
	} 
}