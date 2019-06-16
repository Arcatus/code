#include <iostream>

using namespace std;

int contador = 0;

int binomial(int n, int k)
{
    contador+=1;
    
    if ( k == 0 || k == n )
    {
        return 1;
    }   
    else 
    {
        return binomial(n-1,k) + binomial(n-1,k-1);
    }
}

int main()
{
    int n, k;
    
    cin >> n >> k;
    
    int res = binomial(n,k);
    
    cout<< res << " " << contador << '\n';
    
    return 0;
}