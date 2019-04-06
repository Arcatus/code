#include <iostream>

using namespace std;

int velas(int t, int r)
{
	if (t == 0)
	{
		return 0;
	}
	else
	{
		return (t/r) + velas( t/r ,r);
	}
}

int main( )
{
   int t, r;

   cin >> t >> r;

   if (r==1)
   	return -1;
   else
   	cout << t + velas(t,r) << '\n';
}