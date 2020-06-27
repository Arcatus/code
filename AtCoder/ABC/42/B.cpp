#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    vector<string> st;
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        st.push_back(s);
    }
    sort(st.begin(), st.end());
    for(auto it=st.begin(); it!=st.end(); ++it) {
        cout << *it;
    }
    cout << '\n';
    return 0;
}