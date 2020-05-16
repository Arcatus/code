#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char c;
    bool isGood[200];
    fill(isGood, isGood, false);
    isGood[123] = true;
    isGood[125] = true;
    isGood[91] = true;
    isGood[93] = true;
    isGood[40] = true;
    isGood[41] = true;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    while(scanf("%c",&c) == 1) {
        if ( isGood[c] ) {
            if ( c == '{' ) {
                cnt1++;
            } else if ( c == '}' ) {
                cnt1--;
                if ( cnt1 < 0 ) {
                    cout << "incorrecto\n";
                    return 0;  
                } 
            } else if ( c == '[' ) {
                cnt2++;
            } else if ( c == ']' ) {
                cnt2--;
                if ( cnt2 < 0 ) {
                    cout << "incorrecto\n";
                    return 0;  
                } 
            } else if ( c == '(' ) {
                cnt3++;
            } else if ( c == ')' ) {
                cnt3--;
                if ( cnt3 < 0 ) {
                    cout << "incorrecto\n";
                    return 0;  
                } 
            }
        }
    }
    if ( cnt1 == 0 && cnt2==0 && cnt3==0 ) {
        cout << "correcto\n";
    } else {
        cout << "incorrecto\n";
    }
    return 0;
}   