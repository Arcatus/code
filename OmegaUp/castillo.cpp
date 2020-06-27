#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class t> class ST {
vector<ll> *arr, st; int n;

void build(int u, int i, int j) {
	if (i == j) {
		st[u] = (*arr)[i];
		return;	
	}
	int m = (i+j)/2, l = u*2+1, r = u*2+2;
	build(l, i, m);
	build(r, m+1, j);
	st[u] = t::merge_op(st[l], st[r]);
}

ll query(int a, int b, int u, int i, int j) {
	if (j < a or b < i) return t::neutro;
	if (a <= i and j <= b) return st[u];
	int m = (i+j)/2, l = u*2+1, r = u*2+2;
	ll x = query(a, b, l, i, m);
	ll y = query(a, b, r, m+1, j);
	return t::merge_op(x, y);
}

void update(int a, ll value, int u, int i, int j) {
	if (j < a or a < i) return;
	if (i == j) st[a] += value;
	else {
		int m = (i+j)/2, l = u*2+1, r = u*2+2;
		update(a, value, l, i, m);
		update(a, value, r, m+1, j);
		st[u] = t::merge_op(st[l], st[r]);
	}
}

	public:
	ST(vector<ll>& v) {
		arr = &v;
		n = v.size();
		st.resize(n*4+5);
		build(0, 0, n-1);
	}

	ll query(int a, int b) {
	return query(a, b, 0, 0, n-1);
}

	void update(int a, ll value) {
	update(a, value, 0, 0, n-1);
	}
};

struct RSQ { // range sum query
	static ll const neutro = 0;
	static ll merge_op(ll x, ll y) { return x + y; }
};

struct RMinQ { // range minimun query
	static ll const neutro = LLONG_MAX;
	static ll merge_op(ll x, ll y) { return min(x, y); }
	};

struct RMaxQ { // range maximum query
	static ll const neutro = LLONG_MIN;
	static ll merge_op(ll x, ll y) { return max(x, y); }
};	

struct Back {
	ll position;
	ll val;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, r, x;
	long long k; bool ok;
	cin >> n >> r >> k;
	vector<ll> a;	
	for(int i=0; i<n; ++i) {
		cin >> x;
		a.push_back(x);
	}
	ST<RSQ> stl(a);
	ll lo = 1LL, hi = 1000000000000000000LL;
	int cnt = 0;
	vector<Back> q;
	while( lo < hi ) {
		if (cnt == 65) break; cnt++;
		ok = true;
		ll mid = (hi+lo)/2LL;
		//if(lo == mid) break;
		ll tk = k;
		//cerr << lo << " " << hi << " " << mid << '\n';
		for(int i=0; i<n; ++i) {
			ll defense = stl.query(max(0LL, i-r), min(n-1LL, i+r));
			if ( defense < mid ) {
				if ( defense + tk >= mid ) {
					q.push_back({ min(n-1, i+r), a[min(n-1, i+r)] });
					stl.update( min(n-1, i+r), a[min(n-1, i+r)] + mid - defense );
					tk -= (mid - defense);
				} else {
					ok = false; break;
				}
			}
		}
		if (ok) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << lo << '\n';
	return 0;
}