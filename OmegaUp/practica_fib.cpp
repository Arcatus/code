#include<iostream>
using namespace std;

const int mod = 1000007;

pair<int,int> fib(int n)
{
	if (n == 0) {
		return {0,1};
	} 
	if (n & 1) {	
		auto p = fib(n-1);
		return {p.second,(p.first+p.second)%mod};
		
	} else {
		auto p = fib(n>>1);
		int a = (2*p.first*p.second-p.first*p.first +p.first*mod )%mod;
		int b = (p.first*p.first + p.second*p.second)%mod;
		return {a, b};
	}
}

int main()
{
	int n,x,y;
	cin >> n;
	cout << fib(n).first << '\n';
	return 0;
}