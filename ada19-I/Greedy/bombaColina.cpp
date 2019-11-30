#include <iostream>
#include <algorithm>

using namespace std;

struct robot {
    int altura;
    int energia;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    robot robots[n];

    for (int i=0;i<n;++i) {
        cin >> robots[i].altura >> robots[i].energia;
    }

    sort(robots, robots + n, [](const robot& a, const robot& b)
         { return a.altura + a.energia < b.altura + b.energia;} );

    int altura_bomba = 0;

    for (int i=0; i<n; ++i)
    {
        if ( altura_bomba > robots[i].altura ) {
            robots[i].energia -= ( altura_bomba - robots[i].altura );
        }
        altura_bomba += robots[i].energia;
    }
    cout << altura_bomba << '\n';
}