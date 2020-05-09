#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

#define n 100000
#define m 100000

using namespace std;

int main()
{
    mt19937 generator( time(0) );
    uniform_int_distribution<int> agen(0,26);
    uniform_int_distribution<int> bgen(1,9);
    //cout << negative(generator) << ' ';
    //cout << positive(generator) << ' ';
    //cout << n << " " << k << '\n';
    cout << n << '\n';
	for(int i=0; i<n; ++i) {
        cout << char(bgen(generator)+'A');
    }
}