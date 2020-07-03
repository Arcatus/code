#include <bits/stdc++.h>

using namespace std;
const int nn = 1000000;
vector<int> p(nn), c(nn);
vector<pair<int,int>> ord(nn);
vector<pair<pair<int,int>, int>> a(nn);

void radix_sort() {
    int n = a.size();
    {
        vector<int> cnt(n);
        for(auto i: a) {
            cnt[i.first.second]++;
        }
        vector<int> p(n);
        p[0] = 0;
        for(int i=1; i<n; ++i) {
            p[i] = p[i-1] + cnt[i-1];
        }
        vector<pair<pair<int,int>, int>> new_a(n);
        for(int i=0; i<n; ++i) {
            int x = a[i].first.second;
            new_a[p[x]] = a[i];
            p[x]++;
        }
        a = new_a;
    }
    {
        vector<int> cnt(n);
        for(auto i: a) {
            cnt[i.first.first]++;
        }
        vector<int> p(n);
        p[0] = 0;
        for(int i=1; i<n; ++i) {
            p[i] = p[i-1] + cnt[i-1];
        }
        vector<pair<pair<int,int>, int>> new_a(n);
        for(int i=0; i<n; ++i) {
            int x = a[i].first.first;
            new_a[p[x]] = a[i];
            p[x]++;
        }
        a = new_a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    p.resize(n); c.resize(n); ord.resize(n); a.resize(n);
    for(int i=0; i<n; ++i) ord[i] = {s[i], i};
    sort(ord.begin(), ord.end());
    for(int i=0; i<n; ++i) p[i] = ord[i].second;
    c[p[0]] = 0;
    for(int i=1; i<n; ++i) {
        if( s[p[i]] == s[p[i-1]] ) {
            c[p[i]] = c[p[i-1]];
        } else {
            c[p[i]] = c[p[i-1]] + 1;
        }
    }
    int k = 0;
    while((1<<k) < n) {
        for(int i=0; i<n; ++i) {
            a[i] = {{c[i], c[i+(1<<k)%n]}, i};
        }
        radix_sort();
        for(int i=0; i<n; ++i) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i=1; i<n; ++i) {
            if( a[i].first == a[i-1].first ) {
                c[p[i]] = c[p[i-1]];
            } else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
        k++;
    }
    for(int i=0; i<n; ++i) {
        cout << p[i] << " ";
    }
    cout << '\n';
    return 0;
}