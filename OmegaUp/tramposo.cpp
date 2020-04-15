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
    return a.l < b.l;
}
vector<vector< inter >> ivals(1001);
pair<int,int> df(int k, int a, int b) {
    if ( ivals[k].size()==0 ) {
        int le = max(1, a), ri = min( b, MAXN );
        return {le, ri};
    } else {
        vector<inter> ans;
        int le = 1, ri = ivals[k][0].l - 1, x, y, i;
        for(i=0; i<ivals[k].size()-1; ++i) {
            x = max(a,le);
            y = min(b,ri);
            if ( x <= y ) {
                return {x, y};
            }
            le = ivals[k][i].r + 1;
            ri = ivals[k][i+1].l - 1;
        }
        return {-1,-1};
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
    priority_queue< reg > q;
    q.push( reg{ 1, MAXN, 1, MAXN } );
    int ans = 0;
    while (!q.empty()) {
        reg p = q.top();
        q.pop();
        if ( p.a == n ) {
            ans = max(ans, p.b);
        } else {
            mergeInt(p.a, p.ll, p.rr);
            for(tup i : adj[p.a]) {
                auto [gl, gr] = df(i.d, i.l, i.r);
                if ( gl != -1 ) {
                    int le = max(p.ll, gl);
                    int ri = min(p.rr, gr);
                    if ( le <= ri ) {
                        q.push( reg{ i.d, min(ri-le+1, p.b), le, ri });
                    }
                }
            }
        }
    }
    for(int i=1;i<=n; ++i) ivals[i].clear();

    q.push( reg{ n, MAXN, 1, MAXN } );
    while (!q.empty()) {
        reg p = q.top();
        q.pop();
        if ( p.a == 1 ) {
            ans = max(ans, p.b);
        } else {
            mergeInt(p.a, p.ll, p.rr);
            for(tup i : adj[p.a]) {
                auto [gl, gr] = df(i.d, i.l, i.r);
                if ( gl != -1 ) {
                    int le = max(p.ll, gl);
                    int ri = min(p.rr, gr);
                    if ( le <= ri ) {
                        q.push( reg{ i.d, min(ri-le+1, p.b), le, ri });
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