#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string text, cifrado;
    cin >> text >> cifrado;
    string abc = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    char p, q;
    string ans = "";
    for(int i=text.size()-1; i>=0; i--) {
        ans += text[i];
    }
    string tmp;
    int decipher = cifrado.size()-n, offset=n;
    while( decipher > 0 ) {
        tmp = "";
        int to = min( decipher, (int) text.size() );
        for(int i=to-1; i>=0; i--) {
            p = text[ text.size() - i - 1 ] - 'a';
            q = cifrado[cifrado.size() - offset + (text.size() - i - 1) ];
            int inc = 0;
            while( abc[p] != q ) {
                inc++; p++;
            }            
            tmp += abc[inc];
        }
        decipher -= tmp.size();
        offset += tmp.size();
        text = tmp;
        reverse(tmp.begin(), tmp.end());
        ans += tmp;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}