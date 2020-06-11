#include <bits/stdc++.h>

using namespace std;

struct tup3 {
    int origen, destino, costo;
};
int r[10000+1], p[10000+1];

int findSet(int k) {
    return k == p[k]? k : p[k] = findSet(p[k]);
}

bool isSame(int a, int b) {
    return findSet(a) == findSet(b);
}

void Union(int a, int b) {
    int x = findSet(a), y = findSet(b);
    if ( x == y ) {
        p[y] = x;
        r[x]++;
    } else {
        if (r[x] > r[y]) {
            p[y] = x;
        } else {
            p[x] = y;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<string, int> mapper;
    vector<tup3> e;
    string s, t;
    int o, d, c;
    int ciudad = 0;
    for(int i=0; i<m; ++i) {
        cin >> s >> t >> c;
        if ( mapper.count(s) > 0 ) {
            o = mapper[s];
        } else {
            mapper.insert({ s, ciudad });
            o = mapper[s];
            //cerr << s << " " << ciudad << '\n';
            ciudad++;
        }
        if ( mapper.count(t) > 0 ) {
            d = mapper[t];
        } else {
            mapper.insert({ t, ciudad });
            d = mapper[t];
            //cerr << t << " " << ciudad << '\n';
            ciudad++;
        }
        e.push_back( tup3{ o, d, c } );
    }
    sort(e.begin(), e.end(), [](tup3 a, tup3 b) {
        return a.costo < b.costo;
    });
    int work = n;
    int ans = 0;
    iota(p, p+n, 0);
    for(tup3 i: e) {
        if ( !isSame(i.origen, i.destino) ) {
            ans += i.costo;
            Union(i.origen, i.destino);
            work--;
        }
        if (work==1) break;
    }
    cout << ans << '\n';
    return 0;
}