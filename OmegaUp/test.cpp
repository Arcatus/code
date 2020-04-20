#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int n;
int a[1000+1];
int solve(int i, int k) {
    if ( k == n ) {
        return 0;
    } 
    return ( i+a[k] == 0 ) + ( i-a[k] == 0 ) + solve(i+a[k], k+1) + solve(i-a[k],k+1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i=0; i<n; ++i) cin >> a[i];
  int ans = 0;
  for(int i=0; i<n; ++i) {
      ans += solve(0,i);
  }
  cout << ans << '\n';
  return 0;
}