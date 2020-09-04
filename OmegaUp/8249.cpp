#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

vector<ull> initializeDiffArray(vector<ull>& A) 
{ 
    ull n = A.size(); 

    vector<ull> D(n + 1); 
  
    D[0] = A[0], D[n] = 0; 
    for (ull i = 1; i < n; i++) 
        D[i] = A[i] - A[i - 1]; 
    return D; 
} 

void update(vector<ull>& D, ull l, ull r, ull x) 
{ 
    D[l] += x; 
    D[r + 1] -= x; 
} 

void printArray(vector<ull>& A, vector<ull>& D) 
{ 
    for (ull i = 0; i < A.size(); i++) { 
        if (i == 0) 
            A[i] = D[i]; 
        else
            A[i] = D[i] + A[i - 1]; 
  
        cout << A[i] << " "; 
    } 
    cout << endl; 
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    ull k;
	int n, r;
	cin >> n >> r >> k;
	vector<ull> a(n);
	for(auto& i : a) cin >> i;
    vector<ull> def(n);
    def[0] = 0;
    for(int i = 0; i <= min(n - 1, r); ++i) {
        def[0] += a[i];
    }
    for(int i = 1; i < n; ++i) {
        def[i] = def[i - 1];
        if(i + r < n) {
            def[i] += a[i + r];
        }
        if(i - r - 1 >= 0) {
            def[i] -= a[i - r - 1];
        }
    }
    ull min_global = *min_element(def.begin(), def.end());

	ull lo = min_global, hi = 10000000000000000000ULL;
    int cnt = 0;
	while( lo < hi ) {
        if(cnt == 64) break; cnt++;
        ull mid = (hi + lo)/2ULL + 1ULL;
        //cerr << lo << " " << mid << " " << hi << '\n';
        ull kt = k;
        bool ok = true;
        if(2*r + 1 >= n) {
            if(min_global + kt < mid) {
                ok = false;
            }
        } else {
            vector<ull> b = def;
            vector<ull> D = initializeDiffArray(b);
            for(int i = 0; i < n; i++) {
                ull v = 0;
                    if (i == 0) 
                        v = D[i];
                    else
                        v = D[i] + b[i - 1]; 
                
                if(v < mid) {
                    ull diff = mid - v;
                    if(kt >= diff) {
                        kt -= diff;
                        update(D, i, min(n - 1, i + 2*r), diff); 
                        /*
                        for(int j = i; j <= min(n - 1, i + 2*r); ++j) {
                            b[j] += diff;
                        }
                        */
                    } else {
                        ok = false; break;
                    }
                }
            }
        }
        if(ok) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
	}
	cout << lo << '\n';
	return 0;
}