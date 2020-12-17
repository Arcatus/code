#include <bits/stdc++.h>
// g++ file -fsanitize=address remember check bounds before submit

using namespace std;
using ll = long long;

int n, b;
int p[1000000];
int dp[1000000];
bool visited[1000000];

int cmpSides(int x) {
    int status = -1;
    int ant = (x == 0 ? n-1:x-1);
    int sig = (x == n-1 ? 0: x+1);
    if(p[x]>p[sig]&&p[x]>p[ant]) {
        status = 1;
    } else if(p[x]<p[sig]&&p[x]<p[ant]) {
        status = 2;
    } else if(p[x]>p[sig]&&p[x]<p[ant]) {
        status = 3;
    } else if(p[x]<p[sig]&&p[x]>p[ant]) {
        status = 4;
    } else if(p[x]==p[ant]&&p[x]>p[sig]) {
        status = 5;
    } else if(p[x]>p[ant]&&p[x]==p[sig]) {
        status = 6;
    } else if(p[x]==p[ant]&&p[x]==p[sig]) {
        status = 7;
    } else if(p[x]==p[ant]&&p[x]<p[sig]) {
        status = 8;
    } else if(p[x]<p[ant]&&p[x]==p[sig]) {
        status = 9;
    }
    return status;
}

int sigMultB(int x) {
    return ((x+b)/b)*b;
}

void solve(int x) {
    if(visited[x]) return;
    visited[x] = true;
    int status = cmpSides(x);
    cerr << x << " " << status << '\n';
    int ant = (x == 0 ? n-1:x-1);
    int sig = (x == n-1 ? 0: x+1);
    
    if(dp[x] != -1) return;

    if( status == 2) {
        dp[x] = (p[x]>0 ? b: 0);
        return;
    }
    if( status == 1) {
        solve(ant);
        solve(sig);
        dp[x] = sigMultB(max(dp[ant], dp[sig]));
        return;
    }
    if( status == 3) {
        solve(sig);        
        dp[x] = sigMultB(dp[sig]);
        return;
    }
    if( status == 4) {
        solve(ant);
        dp[x] = sigMultB(dp[ant]);
        return;
    }
    if( status == 5) {
        solve(sig);
        dp[x] = sigMultB(dp[sig]);
        return;
    }
    if( status == 6) {
        solve(ant);
        dp[x] = sigMultB(dp[ant]);
        return;
    }
    if( status == 8) {
        solve(ant);
        dp[x] = sigMultB(dp[ant]);
        return;
    }
    if( status == 9) {
        solve(ant);
        dp[x] = sigMultB(dp[ant]);
        return;
    }
    if( status == 7) { return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> b;
    for(int i = 0; i < n; ++i) cin >> p[i];
    for(int i = 0; i < n; ++i) dp[i] = -1;
    for(int i = 0; i < n; ++i) {
        if(dp[i] == -1) {
            solve(i);
        }
        //cout << i << ": "; for(int i = 0; i < n; ++i) { cout << dp[i] << ' '; } cout << '\n';
    }
    for(int i = 0; i < n; ++i) { cout << dp[i] << ' '; } cout << '\n';
    return 0;
}