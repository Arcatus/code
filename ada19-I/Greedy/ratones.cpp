#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct madrigueras
{
	int posicion;
	int capacidad;
};

bool operator<(const madrigueras& a, const madrigueras& b)
{
	return a.posicion < b.posicion;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int n;

    cin >> n;

    int ratones[n];

    for (int i=0; i<n; ++i) {
    	cin >> ratones[i];
    }

    sort(ratones, ratones+n);

    int m; 
    cin >> m;

    madrigueras mad[m];

    int max_c=0;

    for (int i=0; i<m; ++i) {
    	cin >> mad[i].posicion >> mad[i].capacidad;
    	max_c += mad[i].capacidad;
    }

    if ( n > max_c ) {
    	cout << -1 << '\n';
    	return 0;
    }

    sort(mad, mad+m);

    auto oraculo = [&](const int& t)
    {
    	int capacities[m];

    	for (int i=0; i<m; ++i) {
    		capacities[i] = mad[i].capacidad;
    	}

    	bool assigned;

    	for (int i=0; i<n; ++i) {
    		assigned = false;
    		for ( int j=0; j<m; ++j ) {
    			if (capacities[j] > 0 && abs(mad[j].posicion - ratones[i]) <= t  ) {
    				capacities[j] -= 1;
    				assigned = true;
    				break;
    			}
    		}
    		if ( !assigned ) {
    			return false;
    		}
    	}
    	return true;
    };

    int begin = 0;
    int end = 1000000;

    int time = (begin + end)>>1;

    do {
    	if ( oraculo(time) ) {
    		end = time;
    		time = ( begin + end )>>1;
    	}
    	else {
    		begin = time+1;
    		time = ( begin + end )>>1;
    	}
    } while( begin != end );

    cout << time << '\n';
}