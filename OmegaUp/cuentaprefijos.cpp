#include <bits/stdc++.h>

using namespace std;

int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string palabra;
    unordered_map<string,int> h;
    for(int i=0; i<n; ++i) {
        cin >> palabra;
        for(int j=0; j<palabra.size(); ++j) {
            if ( h.count(palabra.substr(0,palabra.size()-j)) > 0 ) {
                h[palabra.substr(0,palabra.size()-j)]++;
            } else {
                h.insert({ palabra.substr(0,palabra.size()-j), 1 } );
            }
        }
   }
   int m;
   cin >> m;
   for(int i=0; i<m; ++i) {
      cin >> palabra;
      cout << h[palabra] << '\n';
   }
   return 0;
}