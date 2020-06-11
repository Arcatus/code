#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    multimap<int,pair<int,string>, greater<int> > mimap;
    string s;
    int x, cnt = 0;
    for(int i=0; i<n; ++i) {
        cin >> x >> s;
        cnt++;
        mimap.insert({x,{cnt++, s}});
    }
    for(auto it= mimap.begin(); it != mimap.end(); ++it ) {
        cout << it->second.second << '\n';
    }
    return 0;
}