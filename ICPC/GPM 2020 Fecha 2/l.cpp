#include <bits/stdc++.h>
// g++ file -fsanitize=address remember check bounds before submit

using namespace std;
using ll = long long;

int l, c, cnt;
char mat[40+5][40+5];
vector<pair<int,int>> despl;
bool validate(int a, int b, std::set<string> st) {
    int anaval = 0;
    for(auto it = st.begin(); it!=st.end(); ++it) {
        if(anaval>=2) break;
        string s = *it;
        if(s.find(mat[a][b]) == string::npos) continue;
        s.erase(s.find(mat[a][b]), 1);
        string s_full = s;
        for(int j = 0; j < 8; ++j) {
            s = s_full;
            int dx = despl[j].first;
            int dy = despl[j].second;
            int dxi = despl[j].first*(-1);
            int dyi = despl[j].second*(-1);
            int pt1 = a+dy, pt2 = b+dx;
            int pti1 = a+dyi, pti2 = b+dxi;
            int turno = 1;
            bool invalid1=false, invalid2=false;
            while(s.size()>0 && (!invalid1 || !invalid2)) {
                if(turno&1) {
                    if(pt1<0||pt1>=l||pt2<0||pt2>=c||invalid1) {
                        invalid1=true;
                        turno++;
                        continue;
                    }
                    if(s.find(mat[pt1][pt2])!= string::npos) {
                        s.erase(s.find(mat[pt1][pt2]), 1);
                        pt1+=dy;
                        pt2+=dx;
                    } else {
                        invalid1=true;   
                    }
                }
                else {
                    if(pti1<0||pti1>=l||pti2<0||pti2>=c||invalid2) {
                        turno++;
                        invalid2=true;
                        continue;
                    }
                    if(s.find(mat[pti1][pti2])!= string::npos) {
                        s.erase(s.find(mat[pti1][pti2]), 1);
                        pti1+=dyi;
                        pti2+=dxi;
                    } else {
                        invalid2=true;
                    }
                }
                turno++;
            }
            if(s.size()==0) {
                anaval++; break;
            }
        }
    }
    return anaval>=2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> l >> c;
    string s;
    for(int i = 0; i < l; ++i) {
        cin >> s;
        for(int j = 0; j < c; ++j) {
            mat[i][j] = s[j];
        }
    }
    int pal;
    cin >> pal;
    set<string> st;
    for(int i=0; i < pal; ++i) {
        cin >> s;
        st.insert(s);
    }
    despl.push_back({0,-1});
    despl.push_back({1,-1});
    despl.push_back({1,0});
    despl.push_back({1,1});
    despl.push_back({0,1});
    despl.push_back({-1,1});
    despl.push_back({-1,0});
    despl.push_back({-1,-1});
    
    int ans = 0;
    for(int i = 0; i < l; ++i) {
        for(int j = 0; j < c; ++j) {
            if(validate(i, j, st)) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}