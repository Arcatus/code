#include <bits/stdc++.h>

using namespace std;

struct tup {
    int d, l, r;
};

struct reg {
    int a, b, ll, rr;
};

bool operator < (reg a, reg b) {
    return a.b < b.b;
}
unordered_set< string > v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<tup>> adj(1000+1);
    int x, y, l1, r1;
    for(int i=0; i<m; ++i) {
        cin >> x >> y >> l1 >> r1;
        adj[x].push_back({y, l1, r1 });
        adj[y].push_back({x, l1, r1 });
    }
    priority_queue< reg > q;
    q.push( reg{ 1, (int)1e6+1, 1, (int)1e6+1 } );
    while (!q.empty()) {
        reg p = q.top();
        q.pop();
        cerr << "Current max " << p.b << '\n';
        if ( p.a == n ) {
            cout << p.b << '\n';
            return 0;
        }
        if ( v.count( to_string(p.a)+"|"+to_string(p.ll)+"|"+to_string(p.rr) ) == 0 )
        {
            //cerr << "p.a " << p.a << " p.b " << p.b << "\n";
            v.insert( to_string(p.a)+"|"+to_string(p.ll)+"|"+to_string(p.rr) );
            for(tup i : adj[p.a]) {
                if ( v.count( to_string(i.d)+"|"+to_string(i.r)+"|"+to_string(i.r) ) == 0 )
                {
                    //cerr << "p.ll " << p.ll << " p.rr " << p.rr << " | i.l " << i.l << " i.r " << i.r << '\n';
                    int le = max(p.ll, i.l);
                    int ri = min(p.rr, i.r);
                    if ( le <= ri ) {
                        //cerr << "inserting " << i.d << " " << min(ri-le+1,p.b) << " " << le << " " << ri << '\n';
                        q.push( reg{ i.d, min(ri-le+1, p.b), le, ri });
                    }
                }
            }
        }
    }
    cout << "Oh, vamos!\n";
    return 0;
}