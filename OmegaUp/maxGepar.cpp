#include <iostream>
#include <string>
#include <stack>

using namespace std;

int subcadena, result, tmp, n, i;
int findMaxLen(string str) 
{ 
    n = (int)str.length(); 
    stack<int> stk;
    stk.push(-1); 
    for (i=0; i<n; ++i)
        if (str[i] == '(')
          stk.push(i);
        else 
        {
            stk.pop();
            if (!stk.empty()) {
                tmp = (int)i-stk.top();
                if ( tmp > result )
                    result = tmp, subcadena=1;
                else if (tmp==result)
                    subcadena++;
            } else stk.push(i);
        } 
    return result; 
} 

int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    int max = findMaxLen(str);
    if (max==0)
        cout << "0 1" << '\n';
    else cout << max << " " << subcadena << '\n';
    return 0; 
} 