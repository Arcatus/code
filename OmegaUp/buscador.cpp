#include <bits/stdc++.h>

using namespace std;

struct palabra{
    int lcs;
    string nombre;
};

bool operator<(palabra a, palabra b) {
    if ( a.lcs == b.lcs ) {
        return a.nombre.size() < b.nombre.size();
    } else {
        return a.lcs > b.lcs;
    }
}

int main( ) 
{
    string a, b;
    cin >> a;
    int asize = a.size();
    int n;
    cin >> n;
    set< palabra > m;
    for(int i=0; i<n; ++i) {
        cin >> b;
        int bsize = b.size();
        
        int memoria[2][bsize + 1];

        int* actual = memoria[0];
        int* previa = memoria[1];

        for (int i = asize; i >= 0; --i, std::swap(actual, previa)) {
            for (int j = bsize; j >= 0; --j) {
                if (i == asize || j == bsize ) {
                    actual[j] = 0;
                } else if (a[i] == b[j]) {
                actual[j] = 1 + previa[j + 1];
                } else {
                    actual[j] = std::max(actual[j + 1], previa[j]);
                }
            }
        }
        m.insert({previa[0],b});
   }
   auto it = m.begin();
   cout << it->nombre << '\n';
   return 0;
}