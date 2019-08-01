#include <cstdio>
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
    int n;

    scanf("%d",&n);

    int ratones[n];

    for (int i=0; i<n; ++i) {
    	scanf("%d",&ratones[i]);
    }

    int m; 
    scanf("%d",&m);

    madrigueras mad[m];

    int max_c=0;

    for (int i=0; i<m; ++i) {
        scanf("%d %d",&mad[i].posicion,&mad[i].capacidad);
    	max_c += mad[i].capacidad;
    }

    if ( n > max_c ) {
    	printf("-1\n");
    	return 0;
    }

    sort(ratones, ratones+n);
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

    printf("%d\n",time);
}