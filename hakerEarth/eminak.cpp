#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{ 
	ll n;
	cin >> n;
	ll a[n];
	for(ll i=0;i<n;i++)
	cin >> a[i];
	ll count=0;
	for(ll i=0;i<n;i++) {
		ll max=0;
		for(ll j=i+1;j<n;j++) {
			if(a[i]<a[j]) {
				count++;
				break;
			} else if (a[i]>a[j] && a[j]>max) {
				max=a[j];
				count++;
			} else continue;
		}
	}
	cout<<count<<'\n';
	return 0;
}