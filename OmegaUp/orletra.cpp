//#include <iostream>
#include <cstdio>
#include <cctype>
//#include <string>
#include <algorithm>
//#include <string>

int main()
{
	char a[101];

	fgets(a,101,stdin);

	char *ptr = a;

	int indexer = 0;
	int b[101]{};

	while( *ptr != '\0' )
	{
		if (isalpha(*ptr))
		{
			b[indexer++] = *ptr;
		}
		ptr++;
	}

	std::sort(b,b+indexer);

	ptr = a;

	indexer = 0;

	while(*ptr != '\0')
	{
		if (isalpha(*ptr) )
		{
			putchar(b[indexer++]);
		}
		else
		{
			putchar(*ptr);
		}
		ptr++;
	}
}