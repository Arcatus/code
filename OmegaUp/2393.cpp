#include <bits/stdc++.h>

using namespace std;

int n, s1, s2, c, tp;
vector<vector<bool>> ventanas(50+1);
int cnt[51];
int ans, local;
void salto(int k) {
    if ( ventanas[k].size() > cnt[k] ) {
        for(int i=cnt[k]; i<ventanas[k].size(); ++i) {
            ventanas[k][i] = true;
            cnt[k]++;
            local++;
            if ( (k + s1 <= tp) && (ventanas[k+s1].size() > cnt[k+s1]) ) {
                salto(k + s1);
            }
            if ( (k + s2 <= tp) && (ventanas[k+s2].size() > cnt[k+s2]) ) {
                salto(k + s2);
            }
            for(int j=k-1; j >= k-c; j-- ) {
                if ( ventanas[j].size() > cnt[j]) {
                    salto(j);
                }
            }
            ans = max(ans, local);
            local--;
            cnt[k]--;
            ventanas[k][i] = false;
        }
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cin >> n;
    int x;
    for(int i=0; i<n; ++i) {
        cin >> x;
        tp = max(tp, x);
        ventanas[x].push_back(false);
    }
    cin >> s1 >> s2 >> c;
    salto(s1);
    salto(s2);
    cout << ans << '\n';
    return 0;
}