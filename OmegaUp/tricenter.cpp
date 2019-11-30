#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long res = ((3LL * n * (n - 1LL))/2LL)+1LL;
    cout << res << '\n';
    return 0;
}