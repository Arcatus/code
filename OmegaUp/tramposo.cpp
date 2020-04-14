#include <bits/stdc++.h>
#define MAXN 1000005

using namespace std;

struct tup {int d, l, r; };
struct reg { int a, b, ll, rr; };
struct inter{ int l, r; };

bool operator < (reg a, reg b) {
    return a.b < b.b;
}
bool operator < (inter a, inter b) {
    return a.l == b.l ? ( a.r < b.r ) : ( a.l < b.l );
}
vector<vector< inter >> ivals(1001);
vector<inter> df(int k, int a, int b) {
    if ( ivals[k].size()==0 ) {
        vector<inter> ans = { {a, b} };
        return ans;
    } else {
        vector<inter> ans;
        int le, ri, x, y;
        for(int i=0; i<ivals[k].size(); ++i) {
            le = max(a, ivals[k][i].r+1);
            ri = min(b, ( i+1 < ivals[k].size() ) ? ivals[k][i+1].l-1 : MAXN );
            if ( le <= ri ) {
                ans.push_back({le, ri});
            }
        }
        return ans;
    }
}

void mergeInt(int k, int a, int b) {
    ivals[k].push_back({a,b});
    vector<inter> ans = ivals[k];
    sort(ans.begin(), ans.end());
    int index = 0;
    for (int i=1; i<ans.size(); i++) {
        if ( ans[index].r >=  ans[i].l ) {
            ans[index].r = max(ans[index].r, ans[i].r);
        }
        else { 
            ans[++index] = ans[i];
        }
    }
    vector<inter> nuevo;
    for(int i=0; i<=index; ++i) {
        nuevo.push_back( {ans[i].l, ans[i].r} );
    }
    ivals[k].swap(nuevo);
}


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
    for(int i=1; i<=n; ++i) {
        sort(adj[i].begin(), adj[i].end(), []( tup a, tup b ) {
            return (a.r - a.l) > (b.r - b.l);
        } );
    }
    priority_queue< reg > q;
    q.push( reg{ 1, MAXN, 1, MAXN } );
    int ans = 0;
    while (!q.empty()) {
        reg p = q.top();
        //cerr << "p: " << p.a << " " << p.b << " " << p.ll << " " << p.rr << '\n';
        //cerr << "Current max " << p.b << '\n';
        q.pop();
        if ( p.a == n ) {
            //cout << p.b << '\n';
            ans = max(ans, p.b);
            //return 0;
        } else {
            mergeInt(p.a, p.ll, p.rr);
            for(tup i : adj[p.a]) {
                vector<inter> ovps = df(i.d, i.l, i.r);
                if ( ovps.size() > 0 ) {
                    for(inter g: ovps) {
                        int le = max(p.ll, g.l);
                        int ri = min(p.rr, g.r);
                        if ( le <= ri ) {
                            q.push( reg{ i.d, min(ri-le+1, p.b), le, ri });
                        }
                    }
                }
            }
        }
    }
    if ( ans == 0 ) {
        cout << "Oh, vamos!\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}