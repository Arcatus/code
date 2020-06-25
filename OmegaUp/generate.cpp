#include <bits/stdc++.h>

const unsigned long long  n = 100000;
const unsigned long long  h = 10000000;
const unsigned long long  b = 100000;

#define m 100000

using namespace std;

int main(int argc, char **argv)
{
    int mod = 32768;
    mt19937 generator( time(0) );
    srand(time(NULL));
    uniform_int_distribution<int> agen(0,2);
<<<<<<< HEAD
    uniform_int_distribution<unsigned long long> bgen(1,100);
    //cout << n << " " << h << " " << b << '\n';
    cout << 10 << " " << 10 << '\n';
    for(int i=0; i<100; ++i) {
        //cout << char( agen(generator) + 'a' );
        cout << bgen(generator) << ' ';
    }
    cout << '\n';
=======
    uniform_int_distribution<unsigned long long> bgen(1,n);
    //cout << n << " " << h << " " << b << '\n';
    cout << 1 << '\n';
    for(int i=0; i<20; ++i) {
        cout << char( agen(generator) + 'a' );
    }
>>>>>>> 91348413c0cc0ca2c9e5c245fd09ffa3f89ba80d
    /*
    for(int i=0; i<200000; ++i) {
        unsigned long long a = bgen(generator);
        cout << a << '\n';
    }

    char pos[4] = { 'U','D','L','R' };
    cout << n << '\n';
    cout << "D\n";
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