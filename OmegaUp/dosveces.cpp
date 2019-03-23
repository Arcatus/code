//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>
#include <cstring>
#include <cctype>

int main()
{
	char str[100];
	int i = 0;
	while( scanf("%[^\n]",str) == 1)
	{
		i = 0;

		while(str[i])
		{
			putchar(toupper(str[i]));
			i++;
		}
		putchar('\n');
		i = 0;
		while(str[i]) 
		{
			putchar(tolower(str[i]));
			i++;
		}
		putchar('\n');
		getchar();
	}	
}