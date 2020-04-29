#include <bits/stdc++.h>

using namespace std;

int parte(int k, bool p) {
    string a = to_string(k);
    return p ? stoi(a.substr(0,a.size()/2),nullptr,10) : stoi(a.substr(a.size()/2,a.size()/2),nullptr,10);
}

int isprime(int k) {
    if (k == 1) return 0;
    if ( k%2 == 0 ) {
        return k == 2 ? 1:0;
    }
    for(int i=3; i*i <= k; ++i ) {
        if ( k % i == 0 ) return 0;
    }
    return 1;
}

int solve(int k) {
    if ( k < 10 ) {
        return isprime(k);
    } 
    return isprime(k) && solve(parte(k,1)) && solve(parte(k,0));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = solve(n);
    cout << ans << '\n';
    return 0;
}