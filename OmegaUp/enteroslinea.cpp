//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
#include <cstring>
#include <cstdlib>

int main()
{
	char buffer[1000];
	
	int suma;
	int cont;

	char *pch;

	while( scanf("%[^\n]",buffer)==1)
	{
		pch = strtok(buffer," ");
		suma = 0;
		cont = 0;
		
		while( pch != NULL )
		{
			suma += (int) strtol(pch,NULL,10);
			cont++;
			pch = strtok(NULL," ");
		}
		printf("%d %d\n",cont,suma);
		
		getchar();

		char a = getchar();
		
		if (a == '\n')
		{
			while(a == '\n')
			{
				printf("0 0\n");
				a = getchar();
			}
		}
		ungetc(a,stdin);
	}
}