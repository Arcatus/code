//#include <iostream>
#include <cstdio>
#include <cstdlib>
//#include <string>
//#include <algorithm>
//#include <cstring>
//#include <utility>

struct node
{
	int left;
	int right;
	short suma_acumulada = 0;
	bool completed = false;
};

int main()
{
	int n_intervalos, n;

	scanf("%d",&n_intervalos);

	node arr[n_intervalos];

	for (int i = 0; i < n_intervalos; ++i )
	{
		scanf("%d",&arr[i].left);
		scanf("%d",&arr[i].right);
	}

	scanf("%d",&n);

	//short sum_prefix[n/2 + 1];
	short* sum_prefix = (short*) malloc (sizeof(short) * (n/2 + 1) );

	int first_limit = n/2;

	int second_limit = n - first_limit;
	
	sum_prefix[0] = 0;

	for (int i = 1; i <= first_limit; ++i) 
	{
		scanf("%hi",&sum_prefix[i]);
		sum_prefix[i] = sum_prefix[i] + sum_prefix[i-1];
	}
	for (int i = 0; i < n_intervalos; ++i)
	{
		if (arr[i].completed == false )
		{
			if ( arr[i].left <= first_limit && arr[i].right <= first_limit )
			{
				arr[i].suma_acumulada = 
					sum_prefix[ arr[ i ].right ] - sum_prefix[ arr[ i ].left ];
				arr[i].completed = true;
			}
			else if ( arr[i].left < first_limit )
			{
				arr[i].suma_acumulada +=
					sum_prefix[ first_limit ] - sum_prefix[ arr[ i ].left ];
				arr[i].left = 0;
				arr[i].right = arr[i].right - first_limit;
			}
			else if ( arr[i].left >= first_limit )
			{
				arr[i].left -= first_limit;
				arr[i].right -= first_limit;
			}
		}
	}
	
	for (int i = 1; i <= second_limit; ++i) 
	{
		scanf("%hi",&sum_prefix[i]);
		sum_prefix[i] = sum_prefix[i] + sum_prefix[i-1];
	}

	for (int i = 0; i < n_intervalos; ++i)
	{
		if (arr[i].completed == false )
		{
			arr[i].suma_acumulada += 
				sum_prefix[ arr[ i ].right ] - sum_prefix[ arr[ i ].left ];
			arr[i].completed = true;
		}
	}

	for(int i = 0; i < n_intervalos; ++i)
	{
		printf("%hi\n",arr[i].suma_acumulada );
	}

	free(sum_prefix);
}