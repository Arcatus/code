#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n; 
    long long ans= n*(n+1)/2 + 2*( ((n-1)*(n))/2 ) + ((n-2)*(n-1)/2);

    cout << ans << '\n';
}