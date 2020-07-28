#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1000000007;
int main() 
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     int n;
     cin >> n;     
     if(n % 2 == 0) {
     	cout << "white\n";
    	cout << "1 2\n";
     } else {
        cout << "black\n";
     }
     return 0;
}
