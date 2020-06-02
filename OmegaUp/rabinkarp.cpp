#include <bits/stdc++.h>
using namespace std; 
int d, x, y;
void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 
	int i, j; 
	int p = 0; // hash value for pattern 
	int t = 0; // hash value for txt 
	int h = 1; 

	for (i = 0; i < M - 1; i++) {
		h = (h * d) % q; // x^(m-1)
    }

	for (i = 0; i < M; i++) { 
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	} 
	for (i = 0; i <= N - M; i++) { 
		if ( p == t ) { 
            y++;
			for (j = 0; j < M; j++) { 
				if (txt[i+j] != pat[j]) 
					break; 
			}
			if (j == M) 
                x++;
		} 
		if ( i < N-M ) { 
			t = (d*(t - txt[i]*h) + txt[i+M])%q; 
			if (t < 0) 
			t = (t + q); 
		}
	} 
    cout << y << " " << x << '\n';
} 
int main() 
{
    int n, m, x, p;
    char s[100000+1], c[100000+1];
    cin >> m >> c >> n >> s >> x >> p;
	int q = p;
    d = x;
	search(s, c, q); 
	return 0; 
} 
