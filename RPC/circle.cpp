#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double factor = 10.94444099779637902259;
    /*
    double r = 0.2;
    double area = M_PI*r*r;
    while(abs(1.37532 - area*factor) > 1e-6) {
        factor+=0.000001;
    }
    cout << fixed << setprecision(20) << factor << '\n';
    */
    double radius;
    cin >> radius;
    double area = M_PI*radius*radius;
    cout << fixed << setprecision(5) << area*factor << '\n';
    return 0;
}