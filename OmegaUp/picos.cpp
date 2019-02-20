#include <iostream>
#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	uint32_t casos;

	uint32_t supresores;

	uint32_t t, total = 0;

	scanf("%d",&casos);

	for (uint8_t i = 0; i < casos; ++i)
	{
		total = 0;
		scanf("%d",&supresores);

		for ( int j = 0; j < supresores; ++j)
		{
			scanf("%d",&t);
			total+=t;
		}
		printf("%d\n",total-(supresores-1));
	}
}