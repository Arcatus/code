#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c1x1, c1y1, c1x2, c1y2;
    int c2x1, c2y1, c2x2, c2y2;
    cin >> c1x1 >> c1y1 >> c1x2 >> c1y2;
    cin >> c2x1 >> c2y1 >> c2x2 >> c2y2;
    int area1 = abs(c1x2 - c1x1) * abs(c1y2 - c1y1);
    int area2 = abs(c2x2 - c2x1) * abs(c2y2 - c2y1);
    int ans = (area1 + area2);
    if(min(c1x2, c2x2) >= max(c1x1, c2x1) && min(c1y2, c2y2) >= max(c1y1, c2y1)) {
        ans -= abs(min(c1x2, c2x2)-max(c1x1, c2x1))*abs(min(c1y2, c2y2)-max(c1y1, c2y1));
    }
    cout << ans << '\n';
    return 0;
}