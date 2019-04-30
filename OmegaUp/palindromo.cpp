#include <cstdio>
#include <cstring>

int main()
{
	int n;
	scanf("%d",&n); 
	getchar();
	
	char s[1001]; // asuncion n < 1000

	for (int i=0;i<n;++i)
	{
		scanf("%c",&s[i]);
		getchar();
	}
	s[n] = '\0';

	//printf("%s\n",s); 

	int lenght = strlen(s);

	char *ptr1, *ptr2;

	ptr1 = s;

	ptr2 = &s[lenght-1];

	if (lenght%2==1) {
		while ( ptr1 != ptr2 ) {
			if ( *ptr1 == *ptr2 ) {
				ptr1++, ptr2--;
				continue;
			} else {
				printf("No\n");
				return 0;
			}
		}		
		if ( *ptr1 == *ptr2 ) {
			printf("Si\n");
		} else {
			printf("No\n");
		}
	} else {
		int steps = lenght/2;
		while( steps > 0 ) {
			steps--;
			if ( *ptr1 == *ptr2 )
			{
				ptr1++, ptr2--;
				continue;
			} else {
				printf("No\n");
				return 0;
			}
		}
		printf("Si\n");
	}
	return 0;
}