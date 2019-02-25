//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	int n;

	scanf("%d",&n);

	int infi = 1;
	bool state = true;

	if ( n != 0)
	{
		for (int i = 0; i < n; ++i)
		{
			if ( infi == 5 )
			{
				state = false;
			}
			else if ( infi == 1)
			{
				state = true;
			}

			printf("%d ,",infi);

			if ( state ) infi++;
			else infi--;
		}
	}
	printf("\n");
}