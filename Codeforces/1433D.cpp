#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        map<int,int> cnt;
        map<int,queue<int>> posiciones;
        for(int i = 0; i < n; ++i) {
            if(cnt.count(a[i])>0) {
                cnt[a[i]]++;
                posiciones[a[i]].push(i + 1);
            } else {
                cnt.insert({a[i], 1});
                queue<int> q;
                q.push(i+1);
                posiciones.insert({a[i], q});
            }
        }
        if(cnt.size() < 2) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        auto root = cnt.begin();
        auto it = cnt.begin(); it++;        
        int secroot = posiciones[it->first].front();
        for(; it!=cnt.end(); ++it) {
            while(!posiciones[it->first].empty()) {
                cout << posiciones[root->first].front() << " " << posiciones[it->first].front() << '\n';
                posiciones[it->first].pop();
            }
        }
        posiciones[root->first].pop();
        while(!posiciones[root->first].empty()) {
            cout << posiciones[root->first].front() << " " << secroot << '\n';
            posiciones[root->first].pop();
        }
    }
    return 0;
}