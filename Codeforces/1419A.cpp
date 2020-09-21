#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n; string s;
    while(t--) {
        cin >> n >> s;
        int k = 1;
        bool marca[s.size()] = { };
        while(k < n) {
            bool ok = false;
            if(k & 1) {
                for(int i = 0; i < s.size(); i+=2) {
                    if(!marca[i] && (s[i]-'0') % 2 == 0) {
                        ok = true;
                        marca[i] = true;
                        break;
                    }
                }
                if(!ok) {
                    for(int i = 0; i < s.size(); i+=2) {
                        if(!marca[i]) {
                            marca[i] = true;
                            break;
                        }
                    }   
                }
            } else {
                for(int i = 1; i < s.size(); i+=2) {
                    if(!marca[i] && (s[i]-'0') % 2 == 1) {
                        ok = true;
                        marca[i] = true;
                        break;
                    }
                }
                if(!ok) {
                    for(int i = 1; i < s.size(); i+=2) {
                        if(!marca[i]) {
                            marca[i] = true;
                            break;
                        }
                    }   
                }
            }
            k++;
        }
        for(int i = 0; i < n; ++i) {
            if(!marca[i]) {
                cout << ((s[i] - '0') % 2 == 1 ? 1 : 2) << '\n';
                break;
            }
        }
    }
    return 0;
}