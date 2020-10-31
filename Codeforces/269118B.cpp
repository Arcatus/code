#include <bits/stdc++.h>

using namespace std;
const int MAXN = 300001;
vector<int> p(MAXN), c(MAXN);
vector<pair<int,int>> ord(MAXN);
vector<pair<pair<int,int>, int>> a(MAXN);

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
    cin >> s;
    s += "$";
    int n = s.size();
    p.resize(n); c.resize(n); ord.resize(n);
    for(int i=0; i<n; ++i) ord[i] = {s[i], i};
    sort(ord.begin(), ord.end());
    for(int i=0; i<n; ++i) p[i] = ord[i].second;
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
    /*
    for(int i = 0; i < n; ++i) {
        cout << s.substr(p[i], s.size() - p[i]) << '\n';
    }
    */
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
            if(ok) {
                lo = mid;
                break;
            } 
        }
        if(ok) {
            int lele = 0, rile = lo;
            while(lele < rile) {
                ok = true;
                int mid = (rile + lele)/2;
                for(int j=0; j < (int) q.size() && ok; ++j) {
                    if ( s[p[mid] + j] != q[j] ) {
                        ok = false;
                    }
                }
                if(ok) {
                    rile = mid;
                } else {
                    lele = mid + 1;
                }                
            }            
            int leri = lo, riri = n - 1;
            while(leri < riri) {
                ok = true;
                int mid = (leri + riri + 1)/2;
                for(int j=0; j < (int) q.size() && ok; ++j) {
                    if ( s[p[mid] + j] != q[j] ) {
                        ok = false;
                    }
                }
                if(ok) {
                    leri = mid;
                } else {
                    riri = mid - 1;
                }
            }
            cout << leri - (lele - 1) << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}