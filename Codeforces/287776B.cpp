#include <bits/stdc++.h>

using namespace std;


int main()
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     int n;
     cin >> n;
     int a[n];
     for(int i = 0; i < n; ++i) {
          cin >> a[i];
     }
     sort(a, a + n);
     int ptr1 = 0, ptr2 = n - 1;
     int ini = 0;
     int ans[n];
     while(ptr1 <= ptr2) {
          ans[0] = a[ini++];
          ans[n - 1] = a[ini++];
          ans[1] = a[2];
          ans[n - 2] = a[3];
     }
     return 0;
}
