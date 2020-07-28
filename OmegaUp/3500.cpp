#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100001;
vector<int> p(MAXN), c(MAXN);
vector<pair<int,int>> d(MAXN);

void count_sort() {
    int n = p.size();
    vector<int> cnt(n);
    for(auto i: c) {
        cnt[i]++;
    }
    vector<int> new_p(n);
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1; i < n; ++i) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for(auto x: p) {
        int i = c[x];
        new_p[pos[i]] = x;
        pos[i]++;
    }
    p = new_p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(cin >> s) {
        s += "$";
        int n = s.size();
        p.resize(n); c.resize(n); d.resize(n);
        for(int i=0; i<n; ++i) d[i] = {s[i], i};
        sort(d.begin(), d.end());
        for(int i=0; i<n; ++i) p[i] = d[i].second;
        c[p[0]] = 0;
        for(int i=1; i<n; ++i) {
            if( s[p[i]] == s[p[i - 1]] ) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        int k = 0;
        while((1 << k) < n) {
            for(int i=0; i<n; ++i) {
                p[i] = (p[i] - (1 << k) + n) % n;
            }
            count_sort();
            vector<int> c_new(n);
            c_new[p[0]] = 0;
            for(int i = 1; i < n; ++i) {
                pair<int, int> prev = { c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n] };
                pair<int, int> now = { c[p[i]], c[(p[i] + (1 << k)) % n] };
                if(prev == now) {
                    c_new[p[i]] = c_new[p[i - 1]];
                } else {
                    c_new[p[i]] = c_new[p[i - 1]] + 1;
                }
            }
            c = c_new;
            k++;
        }
        cin >> k;
        bool ok;
        string q;
        for(int i = 0; i < k; ++i) {
            cin >> q;
            int lo = 0, hi = n - 1;
            while(lo <= hi) {
                ok = true;
                int mid = lo + (hi-lo)/2;
                for(int j=0; j < (int) q.size() && ok; ++j) {
                    if ( s[p[mid] + j] != q[j] ) {
                        if ( s[p[mid] + j] < q[j] ) {
                            lo = mid+1;
                        } else {
                            hi = mid-1;
                        }
                        ok = false;
                    }
                }
                if(ok) break;
            }
            cout << (ok ? "y\n" : "n\n");
        }
    }
    return 0;
}