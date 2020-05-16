#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k;
    vector<int> a;
    a.reserve(2*n+1);
    for(int i=0; i<n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    a.insert(a.end(), a.begin(), a.end() );
    long long ans = 0;
    long long sum = 0;
    for(int i=0; i<k; ++i) {
        sum += a[i];
    }
    ans = sum;
    for(int i=1; i<a.size()-k; ++i) {
        sum = sum - a[i-1] + a[i+k-1];
        ans = min(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}