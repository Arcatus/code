#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (168 < a)
	{
		if(168 < b)
		{
			if (168  < c)
			{
				printf("NO CRASH\n");
			}	else printf("CRASH %d\n",c);
		} else printf("CRASH %d\n",b);
	}
	else
	{
		printf("CRASH %d\n",a);
	}
	return 0;
}