#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

typedef vector<ll> vll;

vll ret_a, ret_b;

vll primeFactors(ll n)
{ 
    vll ret;
    while (n%2 == 0) {
            ret.push_back(2LL);
            n = n/2;
    }
    for (ll i = 3LL; i <= sqrt(n); i = i+=2LL)
    { 
        while (n%i == 0LL) { 
            ret.push_back(i);
            n = n/i;
        } 
    }
    if (n > 2LL) {
        ret.push_back(n);
    }
    return ret;
} 

int main() 
{ 
    int casos;
    ll a, b;

    cin >> casos;

    for (int i = 0; i < casos; ++i)
    {        
        cin >> a >> b;

        ret_a.clear();
        ret_b.clear();

        ret_a = primeFactors(a);
        ret_b = primeFactors(b);

        vll ret( max( ret_a.size(), ret_b.size() ) );

        auto it = set_intersection(
            ret_a.begin(), ret_a.end(), ret_b.begin(), ret_b.end(), ret.begin());

        ret.resize(it-ret.begin());

        if ( ret.size() > 0 )
            cout << "NO\n";
        else
            cout << "SI\n";
    }
}