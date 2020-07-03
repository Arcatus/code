// NO TESTEADO

#include <bits/stdc++.h>

using namespace std;

struct libro {
    int t;
    bool a;
    bool b;
};

bool operator<(libro a, libro b) {
    return a.t < b.t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int cntAlice=0, cntBob=0;
    libro arr[n];
    priority_queue<libro> p1;
    priority_queue<libro> p2;
    priority_queue<libro> p3;

    for(int i=0; i<n; ++i) {
        cin >> arr[i].t >> arr[i].a >> arr[i].b;
        if(arr[i].a) cntAlice++;
        if(arr[i].b) cntBob++;  
        if( arr[i].a == 0 && arr[i].b == 1 ) {
            p1.push(arr[i]);
        } else if( arr[i].a == 1 && arr[i].b == 0 ) { 
            p2.push(arr[i]);
        } else {
            p3.push(arr[i]);
        }
    }
    if(!p1.empty()) {
        cout << "p1: " << p1.top().t << ' ';
    }
    if(!p2.empty()) {
        cout << "p2: " << p2.top().t << ' ';
    }
    if(!p3.empty()) {
        cout << "p3: " << p3.top().t << ' ';
    }
    cout << '\n';
    if( cntAlice < k || cntBob < k ) {
        cout << -1 << '\n';
    } else {
        int ans = 0;
        while(k>0) {
            if ( !p1.empty() && !p2.empty() && !p3.empty() ) {
                while (p3.top().t <= p1.top().t + p2.top().t ) {
                    ans+=p3.top().t;
                    p3.pop();
                }
            } else if( p1.empty() ) {
                if ( !p3.empty() && !p2.empty() ) {
                    if ( p3.top().t < p2.top().t ) {
                        ans+=p3.top().t;
                        p3.pop();
                    } else {
                        ans+=p2.top().t;
                        p2.pop();
                    }
                } else {
                    if(!p3.empty()) {
                        while(k) {
                            ans+=p3.top().t;
                            k--;
                        }
                    } else {
                        while(k) {
                            ans+=p2.top().t;
                            k--;
                        }
                    }
                }
            } else if( p2.empty() ) {
                if ( !p1.empty() && !p3.empty() ) {
                    if ( p1.top().t < p3.top().t ) {
                        ans+=p1.top().t;
                        p1.pop();
                    } else {
                        ans+=p3.top().t;
                        p3.pop();
                    }
                } else {
                    if(!p1.empty()) {
                        while(k) {
                            ans+=p1.top().t;
                            k--;
                        }
                    } else {
                        while(k) {
                            ans+=p3.top().t;
                            k--;
                        }
                    }
                }
            } else if( p3.empty() ) {
                if ( !p1.empty() && !p2.empty() ) {
                    if ( p1.top().t < p2.top().t ) {
                        ans+=p1.top().t;
                        p1.pop();
                    } else {
                        ans+=p2.top().t;
                        p2.pop();
                    }
                } else {
                    if(!p1.empty()) {
                        while(k) {
                            ans+=p1.top().t;
                            k--;
                        }
                    } else {
                        while(k) {
                            ans+=p2.top().t;
                            k--;
                        }
                    }
                }
            }
            k--;
        }
        cout << ans << '\n';
    }
    return 0;
}