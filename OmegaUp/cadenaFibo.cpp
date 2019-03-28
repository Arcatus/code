#include <iostream>

using namespace std;

typedef unsigned long long ll;

const long mod = 1000000007;

void fib(ll n, ll&x, ll&y){
    if(n==0){
        x = 0;
        y = 1;
        return ;
    }
     
    if(n&1){
        fib(n-1, y, x);
        y=(y+x)%mod;
    }else{
        ll a, b;
        fib(n>>1, a, b);
        y = (a*a+b*b)%mod;
        x = (a*b + a*(b-a+mod))%mod;
    }
}

int main()
{
    ll n, x, y;
    cin >> n;

    ll res = 0;

    for (int i = 1; i <= n; ++i)
    {
        fib(i+2,x,y);
        res += ( x - 1) % mod;
    }
    cout << res << '\n';
}