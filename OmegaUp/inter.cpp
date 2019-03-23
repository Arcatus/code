#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <vector>

int main()
{
	int n;
	scanf("%d",&n);

	int arr[ n ];
	int brr[ n ];	
	int crr[ n ];

	for (int i = 0; i < n; ++i)	
	{
		scanf("%d",&arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&brr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&crr[i]);
	}

	std::sort( arr, arr + n );
	std::sort( brr, brr + n );
	std::sort( crr, crr + n );

	std::vector<int> v1(n);

	std::vector<int> v2(n);

	std::vector<int> result(n);

  	std::vector<int>::iterator it;

	it = std::set_intersection( arr, arr + n, brr, brr+n, v1.begin() );

	v1.resize(it - v1.begin());

	it = std::set_intersection( brr, brr + n, crr, crr+n, v2.begin() );

	v2.resize(it - v2.begin());

	it = std::set_intersection( v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin() );

	result.resize(it - result.begin());


	int ant = -1;

  	for (it= result.begin(); it!= result.end(); ++it)
  	{
  		if (*it == ant)
  		{
  			continue;
  		}
  		else
  		{
  			std::cout << *it << ' ';
  		}	
    	ant = *it;
  	}
  	std::cout << '\n';

}