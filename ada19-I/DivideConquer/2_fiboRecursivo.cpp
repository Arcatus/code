#include <cstdio>

int contador = 0;

int fib(const int& n)
{
    contador++;
    if(n == 0)
    {
		return 0;
    } 
    else if ( n == 1 )
    {
		return 1;
    } 
    else if ( n == 2)
    {
		contador+=2;
		return 1;
    } 
    else if ( n == 3)
    {
		contador+=4;
		return 2;
    }
    return fib(n-1) + fib(n-2);
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d ",fib(n));
	printf("%d\n",contador);
	return 0;
}