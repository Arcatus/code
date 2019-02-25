#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

int main()
{
	int n;
	scanf("%d",&n);

	std::string s;

	std::map<std::string,int> storage;

	int max = 1;
	for(int i = 0; i < n; ++i)
	{
		std::cin >> s;

		std::sort(s.begin(),s.end());

		if ( storage.count(s) > 0 )
		{
			storage[s]++;

			if ( storage[s] > max )
			{
				max = storage[s];
			}
		}
		else
		{
			storage.emplace(s,1);
		}
		
	}
	printf("%d\n",max);
}