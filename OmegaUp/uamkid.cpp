#include <cstdio>

void skip()
{
	int j, ret = 0;

	char buffer[5];

	char tmp;

	for(j = 0; j < 5; j++) 
	{
		tmp = getchar();
		buffer[j] = tmp;
	}

	while( j-1 >= 0)
	{
		if (buffer[j-1]=='#')
		{
			return;
		}
		ungetc(buffer[j-1],stdin);

		j--;
	}
}

int main()
{
	int saltos = 0;

	char i;

	i = getchar();
	do
	{
		if( i == ' ')
		{
			skip();
			saltos++;
		}
		i = getchar();
	} while( i != '\n' );

	printf("%d\n",saltos);
}