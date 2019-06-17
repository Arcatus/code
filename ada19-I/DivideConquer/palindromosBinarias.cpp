#include <iostream>

using namespace std;

int formas(int k, int ant)
{
    if ( k == 0 )
    {
        return 1;
    }
    if ( k == 1 && ant == 0)
    {
        return 1;
    }
    else if ( k == 1 )
    {
        return 2;
    }
    else if ( k == 2 )
    {
        return 1;
    }
    else 
    {
        if ( ant == 0 )
        {
            return formas(k-2,1);
        }
        else
        {
            return formas(k-2,0) + formas(k-2,1);
        }
    }
}

int main()
{
  int n;
  
  cin >> n;
  
  cout << formas(n,-1) << '\n';
  
  return 0;
}