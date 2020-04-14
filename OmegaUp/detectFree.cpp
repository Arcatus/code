#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct inter{ int l, r; };

vector<vector< inter >> ivals(1001);

vector<inter> detectFree(int k, int a, int b) {
    if ( ivals[k].size()==0 ) {
        int le = max(1, a), ri = min( b, MAXN );
        vector<inter> ans = { {le, ri} };
        return ans;
    } else {
        if ( ivals[k][0].l - 1 == 0 ) {
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
        } else {
            vector<inter> ans;
            int le = 1, ri = ivals[k][0].l - 1, x, y, i;
            for(i=0; i<ivals[k].size()-1; ++i) {
                x = max(a,le);
                y = min(b,ri);
                if ( x <= y ) {
                    ans.push_back({x, y});
                }
                le = ivals[k][i].r + 1;
                ri = ivals[k][i+1].l - 1;
            }
            le = ivals[k][i].r + 1, ri = MAXN;
            x = max(a,le), y = min(b,ri);
            if ( x <= y ) {
                ans.push_back({x, y});
            }
            return ans;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ivals[0].push_back({1, 5});
    ivals[0].push_back({10, 15});
    ivals[0].push_back({17, 25});

    vector<inter> a = detectFree(0, 1, 30);
    for(inter i: a ) {
        cout << i.l << " " << i.r << '\n';
    }

    return 0;
}