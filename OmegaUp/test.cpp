<<<<<<< HEAD
#include <stdio.h>
#include <cmath>
=======
#include <bits/stdc++.h>
>>>>>>> 91348413c0cc0ca2c9e5c245fd09ffa3f89ba80d

float xUno{};
float xDos{};
float yUno{};
float yDos{};

<<<<<<< HEAD
float distance = 0.0f;

int main()
{
	int n;

	scanf("%d",&n);

	scanf("%f %f",&xUno ,&yUno);

	float ini_a = xUno;
	float ini_b = yUno;

	for (int i = 1; i < n; i++)
	{
		scanf("%f %f",&xDos ,&yDos);
		//printf("x1:%f y1:%f \n",xUno, yUno);
		//printf("x2:%f y2:%f \n",xDos, yDos);

		double r = hypot( xUno - xDos , yUno - yDos );

		printf("%.9lf\n",r);

		distance += r;

		xUno = xDos;
		yUno = yDos;
	}

	double r = hypot( xDos - ini_a , yDos - ini_b );

	distance += r;
    printf("%.9lf\n",r);
    
	printf("%.2f\n",distance);
=======
string s;
bool used[100+1];
int solve(string s) {
    if (s.size() == 1) return 1;
    else if (s.size() == 2) {
        return s[0] != s[1] ? 1 : 2;
    }
    int ans = 1<<30; char ins;
    for(int i=0; i<s.size()-1; ++i) {
        string t = s;
        if (s[i] != s[i+1]) {
            if (s[i] == 'a' && s[i+1] == 'b' || s[i] == 'b' && s[i+1] == 'a' ) ins = 'c';
            else if (s[i] == 'b' && s[i+1] == 'c' || s[i] == 'c' && s[i+1] == 'b' ) ins = 'a';
            else if (s[i] == 'a' && s[i+1] == 'c' || s[i] == 'c' && s[i+1] == 'a' ) ins = 'b';
            t[i] = ins;
            t.erase(i+1,1);
            ans = min(ans, solve(t));
        }
    }
    return (ans == 1<<30) ? s.size() : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, ans = 0;
    cin >> t;
    while(t--) {
        cin >> s;
        if( s.size() == 1) {
            cout << 1 << '\n';
        } else {
            ans = solve(s);
        }
        cout << ans << '\n';
    }
    return 0;   
>>>>>>> 91348413c0cc0ca2c9e5c245fd09ffa3f89ba80d
}