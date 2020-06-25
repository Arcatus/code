#include <bits/stdc++.h>

using namespace std;

class ZigZag {
    private:
    public:
<<<<<<< HEAD
    static int longestZigZag(vector <int> sequence) {
        int n = sequence.size();
        int memoria[1002][51][2] = { };
        for(int i=0; i<1002; ++i) {
            for(int j=0; j<51; ++j) {
                memoria[i][j][0] = -1;
                memoria[i][j][1] = -1;
            }
        }
        function<int(int,int,bool)> solve = [&](int ant, int j, bool k) {
            if ( memoria[ant][j][k] != -1 ) {
                return memoria[ant][j][k];
            }
            else if ( j == n ) {
                memoria[ant][j][k] = 0;
                return memoria[ant][j][k];
            }
            if ( k ) {
                int tmp = solve(ant, j+1, k);
                if ( sequence[j] < ant ) {
                    tmp = max(tmp, 1 + solve(sequence[j], j+1, !k));
                }
                memoria[ant][j][k] = tmp;
            } else {
                int tmp = solve(ant, j+1, k);
                if ( sequence[j] > ant ) {
                    tmp = max(tmp, 1 + solve(sequence[j], j+1, !k));
                }
                memoria[ant][j][k] = tmp;                
            }
            return memoria[ant][j][k];
        };
        int ans = max( solve(0, 0, 0), solve(1001, 0, 1) );
        return ans;
=======
    int longestZigZag(vector <int> sequence) {
        
>>>>>>> 91348413c0cc0ca2c9e5c245fd09ffa3f89ba80d
    }
};