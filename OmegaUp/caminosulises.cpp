#include <bits/stdc++.h>

using namespace std;
const long long int p = 1000000007;
using ll = long long int;
ll gcdExtended(ll a, ll b, ll *x, ll *y);
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x%m + m) % m;
    return res;
} 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) { 
        *x = 0, *y = 1; 
        return b; 
    } 
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll C = 1, N = 0;
    for(int i=0; i<n; ++i) {
        C = (C*(4*N+2))%p;
        C = (C * modInverse((N+2),p))%p;
        N++;
    }
    cout << C%p << '\n';
    return 0;
}