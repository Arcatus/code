#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

typedef long long ll;

vector<int> primes;

ll _sieve_size;
bitset<1000000+1> bs;

void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;

    bs.set();

    bs[0] = bs[1] = 0;

    for (ll i = 2; i <= _sieve_size; i++) {
        if (bs[i])
        {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        } 
    }
}

void goldbach(ll n)
{ 
    for (ll i=0; primes[i] <= n/2; ++i)
    {
        ll diff = n - primes[i];
  
        if (binary_search(primes.begin(), primes.end(), diff))
        {
            cout << primes[i] << " " << diff << '\n';
            return;
        }
    }
} 

int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve(1000000);

    ll n, t;
    cin >> n;

    for (ll i=0;i<n;++i) {        
        cin >> t;
        goldbach(t);
    }

    return 0; 
} 