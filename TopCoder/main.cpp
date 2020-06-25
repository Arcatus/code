#include <bits/stdc++.h>
<<<<<<< HEAD
//#include "fairworkload.h"
#include "Zigzag.h"
=======
#include "fairworkload.h"
>>>>>>> 91348413c0cc0ca2c9e5c245fd09ffa3f89ba80d

using namespace std;

int main() {
<<<<<<< HEAD
    vector<int> s = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
    int ans = ZigZag::longestZigZag(s);
=======
    vector<int> s = {722, 235, 642, 251, 105, 860, 532, 980, 483, 256, 226, 256, 799, 761, 200};
    int w = 9;
    int ans = FairWorkload::getMostWork(s,w);
>>>>>>> 91348413c0cc0ca2c9e5c245fd09ffa3f89ba80d
    cout << ans << '\n';
}
