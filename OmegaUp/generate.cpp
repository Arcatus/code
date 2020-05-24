#include <bits/stdc++.h>

#define n 100000
#define m 100000

using namespace std;

int main()
{
    int mod = 32768;
    mt19937 generator( time(0) );
    srand(time(NULL));
    uniform_int_distribution<int> agen(0,25);
    uniform_int_distribution<int> bgen(0,1000000000);

    cout << n << " " << m << '\n';
    for(int i=0; i<n; ++i) {
        long long a = bgen(generator);
        cout << a << ' ';
    }
    /*
    cout << '\n';
    cout << m << ' ';
    int a;
    for(int i=0; i<m; ++i) {
        a = bgen(generator);
        cout << a << ' ';
    }
    cout << '\n';
    int x = rand() % mod;
    int p = rand() % mod;
    cout << x << " " << p << '\n';
    //cout << negative(generator) << ' ';
    //cout << positive(generator) << ' ';
    //cout << n << " " << k << '\n';
    cout << n << " " << m << " " << 1000000 << '\n';
    for(int j=0; j<m; ++j) {
        cout << 0 << ' ';
    }
    cout << '\n';
	for(int i=1; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cout << bgen(generator) << ' ';
        }
        cout << '\n';
    }
    cout << (bgen(generator) % m)+1 << " " << (bgen(generator) % m)+1 << '\n';
    */
}