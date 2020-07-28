#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct articulo{
    int t;
    unsigned long long c;
    double cr;
};
 
int main( ){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    articulo arr[n];
    for(int i = 0; i < n; ++ i){
        cin >> arr[i].t >> arr[i].c;
        arr[i].cr = (double) arr[i].t / arr[i].c;
    }
    
    sort(arr, arr + n, [](articulo a, articulo b) {
         if ( a.cr == b.cr ) {
		if (a.c == b.c ) {
		     return a.t > b.t;
		} else {
		     return a.c < b.c;
		}
         } 
         else {
              return a.cr > b.cr;
         }
    });
    /*
    for(int i = 0; i < n; ++i) {
         cerr << arr[i].t << " " << arr[i].c << '\n';
    }
    */
    int ptr1 = 0, ptr2 = n - 1;
    ll ans = 0;
    while(ptr1 <= ptr2) {
         if (arr[ptr1].t == 0) {
               while( arr[ptr1].t == 0 && ptr1 <= ptr2 ) {
                    ans += arr[ptr1].c;
                    ptr1++;
               }
               if (ptr1 <= ptr2 && ptr1 >= 0) ans += arr[ptr1].c; else break;
               ptr2 -= arr[ptr1].t;
               ptr1++;
         } else {
               if (ptr1 <= ptr2 && ptr1 >= 0) ans += arr[ptr1].c; else break;
               ptr2 -= arr[ptr1].t;
               ptr1++;
         }
    }
    cout << ans << '\n';
}
