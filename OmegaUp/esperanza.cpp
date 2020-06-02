#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll h;
int n, s;
string v;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
unordered_set<ll>S;
inline ll hashi(ll a,ll b){
	ll s=a;
	s<<=27;
    s += (b+b+13);
	s<<=13;
	return s;
}
bool solve(){
	pair<int,int>d=make_pair(n+1,n+1);
	h=hashi(d.first,d.second);
	S.insert(h);
	for(int i=0;i<n;i++){
		if(v[i]=='L'){
			d.second--;
		}
		else if(v[i]=='R'){
			d.second++;
		}
		else if(v[i]=='U'){
			d.first++;
		}
		else {
			d.first--;
		}
		h=hashi(d.first,d.second);
		if(S.count(h))return false;
		s=0;
		for(int j=0;j<4;j++){
			ll h2=hashi((d.first+dx[j]),(d.second+dy[j]));
			if(S.count(h2))s++;
			if(s>1)return false;
		}
		S.insert(h);
	}
	return true;
}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	cin>>v;
	if(solve())cout << "S\n";
	else cout << "N\n";
}
