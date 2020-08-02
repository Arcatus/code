#include <bits/stdc++.h>

using namespace std;

struct dato{
    int num, cnt;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;   
    string s;
    while(t--) {
        cin >> s;
        int n = s.size();
        vector<dato> q;
        int cnt;
        for(int i = 0; i < n; ++i) {
            cnt = 0;
            if (s[i] == '1') {
                int k = i;
                while(s[k] == '1') {
                    cnt++; k++;
                }
                i = k - 1;
                q.push_back(dato{1, cnt});
            } else if (s[i] == '2') {
                int k = i;
                while(s[k] == '2') {
                    cnt++; k++;
                }
                i = k - 1;
                q.push_back(dato{2, cnt});
            } else if (s[i] == '3') {
                int k = i;
                while(s[k] == '3') {
                    cnt++; k++;
                }
                i = k - 1;
                q.push_back(dato{3, cnt});
            }
        }
        int ans = INT_MAX;
        if(q.size() < 3) {
            cout << 0 << '\n';
            continue;
        }
        for(int i = 0; i < q.size() - 2; ++i) {
            int b[] = {q[i].num, q[i + 1].num, q[i + 2].num};
            sort(b, b + 3);
            if (b[0] == 1 && b[1] == 2 && b[2] == 3) {
                ans = min(ans, 2 + q[i + 1].cnt);
            }
        }
        cout << (ans == INT_MAX ? 0 : ans ) << '\n';
    }
    return 0;
}