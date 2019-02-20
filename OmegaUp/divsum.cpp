#include <iostream>

using std::cin;

long potencia(int a, int b)
{
	if( b == 0 )
	{	
		return 1;
	}
	else if ( b == 1)
	{	
		return a;
	}
	else
	{
	  int temp = potencia(a, b / 2);
      long res = temp * temp;
      if (b % 2 == 1) {
         res *= a;
      }
      return res;
	}
}

int main()
{
	int n;
	long res = 0;

	cin >> n;

	for( int i = 0; i < 20 ; ++i)
	{
		res = res +  ( n / potencia(2,i) );
	}

	std::cout << res << '\n';
}