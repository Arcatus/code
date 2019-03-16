//#include <iostream>
#include <stdio.h>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	short m;
	int n; int I; int F;
	fpos_t intervals; fpos_t ais;

	scanf("%hi",&m);	

	short t_m = m + 1;

	fgetpos(stdin, &intervals);

	while( t_m > 0 )
	{
		char t = getchar();
		if ( t == '\n')
		{
			t_m--;
		}
	}

	scanf("%d",&n);

	fgetpos(stdin,&ais);

	for ( int i = 0; i < m; ++i)
	{
		fsetpos(stdin,&intervals);
	
		scanf("%d %d",&I,&F);

		fgetpos(stdin,&intervals);

		int vals = F - I;

		fsetpos(stdin,&ais);

		while( I > 0 )
		{
			char t = getchar();
			if ( t == ' ')
			{	
				I--;
			}
		}
		F = 0;
		if ( vals%2 == 0)
		{
			for (int j = 0; j < vals ; j+=2 )
			{
				scanf("%d %d",&I,&n);
				F += I + n;
			}
		}
		else
		{
			scanf("%d",&I);

			F += I;

			for (int j = 1; j < vals ; j += 2 )
			{
				scanf("%d %d",&I,&n);
				F += I + n;
			}	
		}
		
		printf("%d\n",F);
	}
}
