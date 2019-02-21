#include <cstdio>

int main()
{
	int n, mat;

	scanf("%d",&n);

	for(int i = 0; i < n; ++i)
	{
		scanf("%d",&mat);

		if ( mat == 1) 
		{
			scanf("%d",&mat);			
			printf("Simétrica\n");
			continue;
		}
		else if ( mat == 2 )
		{
			int a[mat*mat]{};
			for (int j = 0; j < mat; ++j)
			for (int k = 0; k < mat; ++k)
				scanf("%d",(a+j*mat)+k);
			printf( a[1]==a[2]?"Simétrica\n":"No simétrica\n" );
		}
		else if ( mat >= 3 )
		{
			int a[mat*mat]{};
			for (int j = 0; j < mat; ++j)
			for (int k = 0; k < mat; ++k)
				scanf("%d",(a+j*mat)+k);

			int new_limit = mat, di,salida=0;

			for (di = 0; di <= (mat*mat) - (mat+1); di+=(mat+1))
			{
				for (int sides = 1; sides < new_limit ; ++sides)
				{	
					if  ( a[di + sides] == a[ di+mat*sides ] )
					{
						continue;
					}
					else
					{
						salida=1;
						di = mat*mat;
						sides = new_limit;
					}
				}
				new_limit--;
			}
			if ( salida == 1 )
			{
				printf("No simétrica\n");
			}
			else
			{
				printf("Simétrica\n");
			}
		}
	}
	return 0;	
}