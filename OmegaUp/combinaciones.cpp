#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
#include <algorithm>
#include <vector>
//#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m, i;

	cin >> n >> m;

	ll a = n - m;

	vector<ll> factorsUp;
	vector<ll> factorsBot;

	for (i = 1; i<=n;++i ) {
		factorsUp.push_back(i);
	}

	for (i = 1; i<=a;++i ) {
		factorsBot.push_back(i);
	}
	for (i = 1; i<=m;++i ) {
		factorsBot.push_back(i);
	}

	sort(factorsUp.begin(),factorsUp.end());
	sort(factorsBot.begin(),factorsBot.end());

	int index0=0,index1=0;

	for (int i = 0; i < min(factorsUp.size(),factorsBot.size());++i )
	{
		if (factorsBot[index0] == factorsUp[index1]) {
			factorsBot[index0]=1;
			factorsUp[index1]=1;
			index0++;
			index1++;
		}
		else if(factorsBot[index0] > factorsUp[index1]) {
			index1++;
		}		
		else {
			index0++;
		}
	}	

	ll top=1;
	for (auto& z: factorsUp) {
		top*= z;
	}
	ll bot=1;
	for (auto& z: factorsBot) {
		bot*=z;
	}	
	cout << top / bot << '\n';

	return 0;
}