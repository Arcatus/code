#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

#define n 1000000
#define m 10000
#define MAX_AI 1000000

using namespace std;

int main()
{
    mt19937 generator( time(0) );
    uniform_int_distribution<int> agen(1,9);
    uniform_int_distribution<int> bgen(1,9);
    //cout << negative(generator) << ' ';
    //cout << positive(generator) << ' ';
    //cout << n << " " << k << '\n';
	for(int i=0; i<n-1; ++i) {
        cout << bgen(generator);
    }
	cout << '\n';
	cout << m-1 << '\n';
	for(int i=0; i<m-1; ++i) {
		cout << agen(generator) << '\n';
	}
}