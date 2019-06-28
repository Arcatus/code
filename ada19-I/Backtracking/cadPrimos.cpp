#include <iostream>

using namespace std;

int n, contador;

bool primos[100];

void sieve()
{
    primos[0] = primos[1] = true;

    for (int i=2;i<100;++i) {
        if ( !primos[i] )
        {
            for (int j=i+i;j<100; j+=i) {
                primos[j] = true;
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
            if (k == 0 || !primos[ num*10 + i ] )
            {
                calcula(k+1,i);
            }
        }
    }
}

int main()
{

    cin >> n;

    sieve();

    calcula(0,0);

    cout << contador << '\n';
}