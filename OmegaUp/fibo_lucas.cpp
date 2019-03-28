#include <iostream>

/*
    Created by CarlosAlberto1x9
    27 marzo 2019
*/

using namespace std;

typedef unsigned long long llu;

const long mod = 1000000007;


void fib(llu n, llu&x, llu&y){
    if(n==0){
        x = 0;
        y = 1;
        return ;
    }
     
    if(n&1){
        fib(n-1, y, x);
        y=(y+x)%mod;
    }else{
        llu a, b;
        fib(n>>1, a, b);
        y = (a*a+b*b)%mod;
        x = (a*b + a*(b-a+mod))%mod;
    }
}

int main()
{
    llu n, x, y;
    cin >> n;

    if ( n < 3)
    {
        cout << (( n == 1)?"1":"3") << '\n';
    }
    else
    {
        fib(n+4,x,y);

        llu neg = -1*((n+1)%mod);

        llu res = x + neg - 2;

        cout << res << '\n';
    }
}