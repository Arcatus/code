#include <iostream>
#include <algorithm>
#include <cstring>
 
#define MAX 1000000000
 
using namespace std;
 
typedef long long ll;
 
ll n, w;
ll p[100+1], v[100+1];
 
ll memo[100+1][100000+1];

ll mochila(ll i, ll k)
{
    if (k == 0) return 0;
    else if ( i == n ) return MAX;
 
    if ( memo[i][k] != -1) return memo[i][k];
 
    if ( v[i] <= k ) {
        memo[i][k] = min( p[i] + mochila(i+1, k - v[i] ), mochila(i+1,k));
    } else {
        memo[i][k] = mochila(i+1,k);
    }
    return memo[i][k];
}
 
int main()
{
    cin >> n >> w;
    int max_v = 0;
    for(int i=0; i<n; ++i) {
        cin >> p[i] >> v[i];
        max_v += v[i];
    }
 
    for(int i=0; i<=100; ++i){
        for(int j=0; j<=100000; ++j) {
            memo[i][j] = -1;
        }
    }
 
    int ans = -1, peso;
 
    for(ll i=1; i<=max_v;++i) {

        peso = mochila(0,i);
        if (peso <= w) ans = i;
    }
    cout << ans << '\n';
}