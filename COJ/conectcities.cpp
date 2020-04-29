#include <cstdio>
#include <utility>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

int lider[10001];
int   tam[10001];

int findSet(int x) {
   if (lider[x] != x) {
      lider[x] = findSet(lider[x]);
   }
   return lider[x];
}

bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}

void unionSetBySize(int i, int j) {
   int x = findSet(i);
   int y = findSet(j);

   if (x != y) {
      if (tam[y] < tam[x]) {
         swap(x, y);
      }
      lider[x] = y;
      tam[y] += tam[x];
   }
}

int main()
{
	int casos, x, y, w, v, e, p;
	scanf("%d",&casos);

	for (int z=0;z<casos;++z)
	{
      	vector< pair<int, ii> > old_edges;
      	vector< pair<int, ii> > new_edges;

      	scanf("%d",&v);
      	scanf("%d",&e);

		for (int i = 0; i < e; i++) {
			scanf("%d %d %d",&x, &y, &w);
			old_edges.push_back(make_pair(0, ii(x, y)));
		}

		scanf("%d",&p);
		for (int i = 0; i < p; i++) {
			scanf("%d %d %d",&x, &y, &w);
			new_edges.push_back(make_pair(w, ii(x, y)));
		}

		iota(lider+1, lider+v+1, 1);
		
		fill(tam+1, tam+v+1, 1);
      	
      	int num_subsets = v;

		for (int i = 0; i < e && num_subsets > 1; ++i) {
			pair<int,ii> front = old_edges[i];

			if ( ! isSameSet( front.second.first, front.second.second ) ) {
				unionSetBySize( front.second.first, front.second.second );
            	num_subsets-=1;
			}
		}

		if ( num_subsets == 1) {
			printf("Thank you, Goodbye\n");
			continue;
		}

		long long costo = 0;
		sort(new_edges.begin(), new_edges.end(), [](const pair<int,ii>& p1, const pair<int,ii>& p2) {
         return p1.first < p2.first;
		});

		for (int i = 0; i < p && num_subsets > 1; ++i) {
			pair<int,ii> front = new_edges[i];

			if ( ! isSameSet( front.second.first, front.second.second ) ) {
				costo += front.first;
				unionSetBySize( front.second.first, front.second.second );
				num_subsets-=1;
			}
		}

		if ( num_subsets == 1 ) {
			printf("%lld\n",costo);
		}
		else {
			printf("You better hire someone else\n");
		}
	}
	return 0;
}