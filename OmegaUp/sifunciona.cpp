#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char c;
    stack<int> p; // 1 {}  2 []  3()
    while(scanf("%c",&c) == 1) {
            if ( c == '{' ) {
                p.push('{');
            } else if ( c == '}' ) {
                if ( p.top() == '{' ) {
                    p.pop();
                } else {
                    cout << "incorrecto\n";
                    return 0;
                }
            } else if ( c == '[' ) {
                p.push('[');
            } else if ( c == ']' ) {
                if ( p.top() == '[' ) {
                    p.pop();
                } else {
                    cout << "incorrecto\n";
                    return 0;
                }
            } else if ( c == '(' ) {
                p.push('(');
            } else if ( c == ')' ) {
                if ( p.top() == '(' ) {
                    p.pop();
                } else {
                    cout << "incorrecto\n";
                    return 0;
                }
            }
    }
    cout << "correcto\n";
    return 0;
}