//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int k;
	int a, b, x, y;

	scanf("%d",&k);

	while ( k != 0 )
	{
		scanf("%d %d",&a,&b);

		for ( int i = 0 ; i < k; ++i)
		{
			scanf("%d %d",&x,&y);

			if ( a == x || b == y)
			{
				printf("divisa\n");
			}
			else if ( x > a && y > b )
			{
				printf("NE\n");
			}
			else if ( x < a && y > b)
			{
				printf("NO\n");
			}
			else if ( x > a && y < b)
			{
				printf("SE\n");
			}
			else 
			{
				printf("SO\n");
			}
		}
		scanf("%d",&k);
	}
}