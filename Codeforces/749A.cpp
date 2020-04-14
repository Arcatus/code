#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;

/* Greedy recursive aproach
void bachgold(int n)
{
	if ( n == 0 ) {
		return;
	} else {
		if ( n == 3 ) {
			primes.push_back(3);
			return bachgold(n-3);
		} else {
			primes.push_back(2);
			return bachgold(n-2);
		}
	}
}
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	//bachgold(n);
	//cout << primes.size() << '\n';

	int contador=0;

	while( n!= 0) {
		contador+=1;
		if ( n == 3 ) {
			primes.push_back(3);
			n-=3;
		} else {
			primes.push_back(2);
			n-=2;
		}
	}
	cout << contador << '\n';
	for(int i: primes) {
		cout << i << ' ';
	}
}