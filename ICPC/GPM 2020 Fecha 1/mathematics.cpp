#include <bits/stdc++.h>

using namespace std;
using ll = long long;
string s, tmp; int n, p;
ll a[3]; bool ok;
bool prime[1000000+1];
void SieveOfEratosthenes(int n) {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        } 
    }
} 
bool isprime(int x) {
    return prime[x];
}
ll minimo_global = LLONG_MAX;

void solve(int p, int used) {
    if(p > 3) return;
    if(p == 3 && used == n) {
        ok = true;
        int vali = 0;
        vali += to_string(a[0]).size();
        vali += to_string(a[1]).size();
        vali += to_string(a[2]).size();
        if(vali != n) return;
        minimo_global = min(minimo_global, a[0]*a[1]*a[2]);
    }
    string oldtmp;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '-') continue;
        char t = s[i];
        oldtmp = tmp;
        tmp = tmp + t;
        s[i] = '-';
        solve(p, used + 1);
        if(tmp[0] != '0' && p < 3 && used < n) {
            ll vv = atoll(tmp.c_str());
            if(vv < 1000001 && s[0] != '0' && isprime(vv)) {
                a[p] = vv;
                tmp = "";
                solve(p + 1, used + 1);
            }
        }
        tmp = oldtmp;
        s[i] = t;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;    
    n = s.size();
    SieveOfEratosthenes(999999);
    solve(0, 0);
    if(ok && minimo_global != LLONG_MAX) {
        cout << minimo_global << '\n';
    } else {
        cout << "Bob lies\n";
    }
    return 0;
}