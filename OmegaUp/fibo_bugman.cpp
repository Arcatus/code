#include <iostream>

using namespace std;

typedef long long ll;

const long mod = 2017;

void fib(ll n, ll&x, ll&y){
    
    if( n == 0 ) // caso base
    {
        x = 0;
        y = 1;
        return;
    }
     
    if( n&1 ) // numeros impares
    {
        fib(n-1, y, x);
        y = ( y + x ) % mod;
    }
    else // numeros pares (el right shift significa division entre 2)
    {
        ll a, b;
        fib(n>>1, a, b);

        y = (a*a+b*b)%mod;
        x = (a*b + a*(b-a+mod))%mod;
    }
}

int main()
{
    ll n, x = -1, y = -1;
    cin >> n;

    fib(n,x,y);

    cout << x << '\n';    
}