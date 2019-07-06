#include <iostream>

using namespace std;

int n, contador;

bool primos[100];

void sieve()
{
    primos[0] = primos[1] = false;

    for (int i=2;i<100;++i)
    {
        if (primos[i] != false)
        {
            for (int j=i+i;j<100; j+=i) {
                primos[j] = false;
            }
        }
    }
}

void calcula(int k, int num)
{
    if (k == n) {
        contador+=1;
        return;
    }
    else
    {
        for( int i=0; i<=9; ++i)
        {
            if ( primos[ num*10 + i ] )
            {
                calcula(k+1,i);
            }
        }
    }
}

int main()
{
    cin >> n;

    for(int i=0;i<100;++i) primos[i]=true;

    sieve();

    for (int i=0; i<=9; ++i)
    {
        calcula(1,i);
    }    

    cout << contador << '\n';
}