#include <bits/stdc++.h>

using namespace std;

class FairWorkload {
    private:
    public:
    static int getMostWork(vector<int> folders, int workers) {
        int l = *max_element(folders.begin(),folders.end()); 
        int r = accumulate(folders.begin(), folders.end(), 0);
        while( l < r ) {
            int m = l + (r-l)/2;
            int w = 1, acc = 0;
            for(int i: folders) {
                if ( acc + i <= m ) {
                    acc += i;
                } else {
                    ++w;
                    acc = i;
                }
            }
            if ( w <= workers ) {
                r = m;
            } else {
                l = m+1;
            }
        }
    return l;
    }
};