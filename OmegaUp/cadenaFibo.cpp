#include <stdio.h>

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
    
    scanf("%llu",&n);

    if ( n < 3)
    {
        printf(( n == 1)?"1":"3");
    }
    else
    {
        fib(n+4,x,y);

        llu neg = -1*((n+1)%mod);

        llu res = x + neg - 2;

        printf("%llu\n",res);
    }
}