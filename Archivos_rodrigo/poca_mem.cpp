//#include <iostream>
#include <cstdio>
//#include <cstdlib>
//#include <string>
//#include <algorithm>
//#include <cstring>
//#include <utility>

//#define _DEBUG_PM_ 0x0001

struct node
{
	int left;
	int right;
	int suma_acumulada = 0;
	bool completed = false;
};

int main()
{
	bool shouldClose = false;

	int n_intervalos, n;

	scanf("%d",&n_intervalos);

	node arr[n_intervalos];

	for (int i = 0; i < n_intervalos; ++i )
	{
		scanf("%d",&arr[i].left);
		scanf("%d",&arr[i].right);
	}

	scanf("%d",&n);
	
	int bit;

	if ( n < 10)
		bit = n;
	else
		bit = 100;

	int calculated = 0;

	int sum_prefix[ bit + 1 ]{};
	
	sum_prefix[0] = 0;

	while( ! shouldClose )
	{
		if ( calculated + bit >= n )
		{
			bit = n - calculated;
			shouldClose = true;
		}

		for(int i = 1; i <= bit; ++i)
		{
			scanf("%d",&sum_prefix[i]);
			sum_prefix[i] = sum_prefix[i] + sum_prefix[i-1];
		}

		#ifdef _DEBUG_PM_
		for(auto& i: sum_prefix)
		{
			printf("%d ",i);
		}printf("\n");

		for(int i = 0; i< n_intervalos; ++i)
		{
			printf("%d ",arr[i].suma_acumulada);
		}printf("\n\n");
		#endif

		for (int i = 0; i < n_intervalos; ++i)
		{
			if ( arr[i].completed == false )
			{
				#ifdef _DEBUG_PM_
				printf("l:%d r:%d ",arr[i].left,arr[i].right);
				#endif
				if ( arr[i].left <= bit && arr[i].right <= bit )
				{
					arr[i].suma_acumulada 
						+= sum_prefix[ arr[i].right ] - sum_prefix[ arr[i].left ];
					arr[i].completed = true;
				}
				else if ( arr[i].left <= bit && arr[i].right > bit )
				{
					arr[i].suma_acumulada 
						+= sum_prefix[ bit ] - sum_prefix[ arr[i].left ];
					arr[i].left = 0;
					arr[i].right -= bit;
				}
				else
				{
					arr[i].left -= bit;
					arr[i].right -= bit;
				}
				#ifdef _DEBUG_PM_
				printf(" -> l:%d r:%d ",arr[i].left,arr[i].right);
				printf("\n");
				#endif
			}
		}
		calculated += bit;
	}

	for(int i = 0; i < n_intervalos; ++i)
	{
		printf("%d\n",arr[i].suma_acumulada );
	}
}