//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int velocity[1000 +1];
int position[1000 +1];

int in_track;

int main()
{
	int n, t, overtakes = 0;

	scanf("%d",&n);

	for (int i=0; i < n; ++i)
	{
		scanf("%d",&velocity[i]);
	}

	position[0] = velocity[n-1]; in_track++;

	int starting;

	for (int i = n - 2; i >= 0; i--)
	{		
		starting = velocity[i];

		for ( int j = 0; j < in_track ; ++j)
		{
			if ( starting > position[j] )
			{	
				overtakes++;
			}
		}
		position[in_track++] = starting;
	}
	printf("%d\n",overtakes);

}