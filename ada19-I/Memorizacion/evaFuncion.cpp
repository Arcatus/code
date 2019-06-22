#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll memoria[110];

ll funcion(ll k)
{
    if ( k == 0 ) {
        return 1;
    }
    else if ( k > 0)
    {
        if ( memoria[k] == 0 ) {
            memoria[k] = 1 + funcion(-k+1);
        }
        return memoria[k];
    }
    else
    {
        if ( memoria[k+101] == 0 ) {
            memoria[k+101] = 2 + funcion(-k) + funcion(k+1);
        }
        return memoria[k+101];
    }
}

int main()
{
    ll n;
    cin >> n;
    cout << funcion(n) << '\n';
}