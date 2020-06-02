#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<string,int> db;
    string s;
    for(int i=0; i<n; ++i) {
        cin >> s;
        if( db.count(s) == 0 ) {
            db.insert({ s, 0 });
            cout << "OK\n";
        } else {
            db[s]++;
            s = s + to_string( db[s] );
            db.insert({s, 0});
            cout << s << '\n';
        }
    }
    return 0;
}
