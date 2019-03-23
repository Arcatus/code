//#include <iostream>
#include <cstdio>
#include <cstdlib>
//#include <string>
//#include <algorithm>
//#include <cstring>
//#include <utility>

//#define _DEBUG_PM_ 0x0001

#define division_rate 8 // must be > 0

struct node
{
	int left;
	int right;
	int suma_acumulada = 0;
	bool completed = false;
};

int* generate_limits(const int& n)
{
	int* limits = (int*) malloc (sizeof(int) * division_rate);

	int t = n / division_rate;

	limits[0] = t;

	for ( int i = 1; i < division_rate - 1; ++i )
	{
		limits[i] += t;
	}
	limits[ division_rate - 1 ] = n - t*(division_rate-1);

	return limits;
}

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

	int sum_prefix[n/division_rate + (division_rate%2==0)?0:(2) ]{};

	int* limits = generate_limits(n);
 
	for (int i = 0; i < division_rate; ++i )
	{
		printf("limit:%d\n",limits[i]);
	}

	return 0;
	
	sum_prefix[0] = 0;

	int first_limit = 0;
	int second_limit = 0;
	int third_limit = 0;

	for (int i = 1; i <= first_limit; ++i) 
	{
		scanf("%d",&sum_prefix[i]);
		sum_prefix[i] = sum_prefix[i] + sum_prefix[i-1];
	}
	#ifdef _DEBUG_PM_
	for (auto& i: sum_prefix) 
		{
			printf("%d ",i);
		}
	printf("\nSumas acumuladas:");
	for(auto& j: arr)
	{
		printf("%d ",j.suma_acumulada);
	}printf("\n");
	#endif

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
			
			else if ( arr[i].left < first_limit && arr[i].right 
						<= first_limit + second_limit + third_limit )
			{
				arr[i].suma_acumulada +=
					sum_prefix[ first_limit ] - sum_prefix[ arr[ i ].left ];
				arr[i].left = 0;
				arr[i].right = arr[i].right - first_limit;
			}
			else
			{
				arr[i].left -= first_limit;
				arr[i].right -= first_limit;
			}
		}
	}
	
	for (int i = 1; i <= second_limit; ++i) 
	{
		scanf("%d",&sum_prefix[i]);
		sum_prefix[i] = sum_prefix[i] + sum_prefix[i-1];
	}

	#ifdef _DEBUG_PM_
	for (auto& i: sum_prefix) printf("%d ",i);
		printf("\nSumas acumuladas:");
	for(auto& j: arr)
	{
		printf("%d ",j.suma_acumulada);
	}printf("\n");
	#endif

	for (int i = 0; i < n_intervalos; ++i)
	{
		if (arr[i].completed == false )
		{
			if ( arr[i].left <= second_limit
					&& arr[i].right <= second_limit )
			{
				arr[i].suma_acumulada += 
					sum_prefix[ arr[ i ].right ] - sum_prefix[ arr[ i ].left ];
				arr[i].completed = true;
			}
			else if ( arr[i].left < second_limit
					&& arr[i].right <= second_limit + third_limit )
			{
				arr[i].suma_acumulada +=
					sum_prefix[ second_limit ] - sum_prefix[ arr[ i ].left ];

				arr[i].left = 0;
				arr[i].right = arr[i].right - second_limit;
			}
			else
			{
				arr[i].left -= second_limit;
				arr[i].right -= second_limit;
			}
		}
	}

	for (int i = 1; i <= third_limit; ++i) 
	{
		scanf("%d",&sum_prefix[i]);
		sum_prefix[i] = sum_prefix[i] + sum_prefix[i-1];
	}

	#ifdef _DEBUG_PM_
	for (auto& i: sum_prefix) printf("%d ",i); 
		printf("\nSumas acumuladas:");
	for(auto& j: arr)
	{
		printf("%d ",j.suma_acumulada);
	}printf("\n");
	#endif

	for (int i = 0; i < n_intervalos; ++i)
	{
		if (arr[i].completed == false )
		{
			#ifdef _DEBUG_PM_
			printf("derecha:%d izquierda:%d\n",arr[i].right,arr[i].left );
			#endif

			arr[i].suma_acumulada += 
				sum_prefix[ arr[ i ].right ] - sum_prefix[ arr[ i ].left ];
		}
	}

	#ifdef _DEBUG_PM_
	for (auto& i: sum_prefix) printf("%d ",i); 
		printf("\nSumas acumuladas:");
	for(auto& j: arr)
	{
		printf("%d ",j.suma_acumulada);
	}printf("\n");
	#endif

	for(int i = 0; i < n_intervalos; ++i)
	{
		printf("%d\n",arr[i].suma_acumulada );
	}
}