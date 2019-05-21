//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>
#include <cstdlib>

int main()
{
	fseek(stdin,0,SEEK_END);

	char size = ftell(stdin);

	rewind(stdin);

	printf("%d\n",size);

	char *buffer = (char *) malloc (sizeof(char)*size);

	size_t result = fread(buffer, 1, size, stdin );

	printf("%zu\n",result);


}