#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;
 
vector <int> primes;

int _sieve_size;
bitset<10000010> bs;

void sieve(int upperbound)
{
    _sieve_size = upperbound + 1;

    bs.set();

    bs[0] = bs[1] = 0;

    for (int i = 2; i <= _sieve_size; i++) {
        if (bs[i])
        {
            for (int j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back(i);
        } 
    }
}

void goldbach(int n)
{ 
    for (int i=0; primes[i] <= n/2; ++i)
    { 
        int diff = n - primes[i];
  
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
    sieve(10000);
  
    int n;
    cin >> n;
    int t;
    for (int i=0;i<n;++i)
    {
        cin >> t;
        goldbach(t);
    }

    return 0; 
} 