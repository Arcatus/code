#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long k;
    cin >> k;
    char buffer[1000005] = "codeforces";
    k--;
    fwrite(&buffer,1,10,stdout);
    for(int i=0; i<1000000; ++i) buffer[i] = 's';
    long long m = k/1000000;
    for(int i=0; i<m; ++i) {
        fwrite(&buffer,1,1000000,stdout);
    }
    m = k%1000000;
    fwrite(&buffer,1,m,stdout);
    return 0;
}