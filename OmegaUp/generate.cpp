#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <unordered_set>

#define n 500
#define m 1500
#define MAX_AI 1000000

using namespace std;

int main()
{
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cout.tie(0);

	cout << n << " " << m <<'\n';

	for(int i=0; i<m; ++i) {
		int a= rand()%n + 1;
		int b= rand()%n + 1;
		if ( a > b ) swap(a,b);
		int l = rand()%MAX_AI +1;
		int r = rand()%MAX_AI +1;
		if( l > r ) swap(l,r);
		cout << a << " "<< b << " "<< l << " "<< r << '\n';
	}

}