//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
//#include <utility>

struct interval
{
	short indice;
	int left;
	int right;
};

bool left_comparer(interval a, interval b)
{
	return a.left < b.left;
}

bool index_comparer(interval a, interval b)
{
	return a.indice < b.indice;
}

int main()
{
	interval arr[3];

	arr[0].indice = 0;
	arr[1].indice = 1;
	arr[2].indice = 2;
	
	arr[0].left = 1; 
	arr[1].left = 2; 
	arr[2].left = 0;

	arr[0].right = 3; 
	arr[1].right = 4; 
	arr[2].right = 5;

	std::sort(arr, arr+3, left_comparer);

	printf("Left comparer\n");
	for(int i = 0; i < 3; ++i)
	{
		printf ( "%d -> [%d %d)\n" , arr[i].indice, arr[i].left, arr[i].right);
	}

	std::sort(arr, arr+3, index_comparer);	

	printf("Index comparer\n");

	for(int i = 0; i < 3; ++i)
	{
		printf ( "%d -> [%d %d)\n" , arr[i].indice, arr[i].left, arr[i].right);
	}	

}