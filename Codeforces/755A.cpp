#include <iostream>

using namespace std;

bool isPrime(int k)
{
    if ( k % 2 == 0 ) {
        return ( k == 2 )?true:false;
    }
    for(int i=3; i*i<=k; i+=2 ) {
        if ( k%i == 0 ) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;

    cin >> n;

    for(int m=0; m<1001; ++m  ) {
        if( !isPrime(m*n + 1) ) {
            cout << m << '\n';
            return 0;
        }
    }
}