//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	for (int i = 1; i <= 1000;++i)
	{
		if (i%3==0 && i%5==0)
		{
			printf("FizzBuzz\n");
		}
		else if (i%3==0)
		{
			printf("Fizz\n");
		}
		else if (i%5==0)
		{
			printf("Buzz\n");
		}	
		else
		{
			printf("%d\n",i);
		}
	}
}