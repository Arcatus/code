#include <cstdio>
#include <cstring>

int main()
{
	char s[1000] = {};

	scanf("%s",s);

	int lenght = strlen(s);

	char *ptr1, *ptr2;

	ptr1 = s;

	ptr2 = &s[lenght-1];

	if (lenght%2==1)
	{
		while ( ptr1 != ptr2 )
		{
			if ( *ptr1 == *ptr2 )
			{
				ptr1++;
				ptr2--;
				continue;
			}
			else
			{
				printf("Falso\n");
				return 0;
			}
		}		
		if ( *ptr1 == *ptr2 )
		{
			printf("Cierto\n");
		} 
		else
		{
			printf("Falso\n");
		}
	}
	else
	{
		int steps = lenght/2;
		while( steps > 0 )
		{
			steps--;
			if ( *ptr1 == *ptr2 )
			{
				ptr1++;
				ptr2--;
				continue;
			}
			else
			{
				printf("Falso\n");
				return 0;
			}
		}
		printf("Cierto\n");
	}
	return 0;
}